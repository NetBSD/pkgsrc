<?php
# $NetBSD: pear_plist.php,v 1.6 2009/01/19 19:55:02 abs Exp $
# Parses package XML file and outputs appropriate PLIST

$PEAR_LIB = getenv('PEAR_LIB');
$WRKSRC = getenv('WRKSRC');
$PEAR_DIRRM_BASEDIR = getenv('PEAR_DIRRM_BASEDIR');
$PEAR_DIRRM_EXCLUDE = getenv('PEAR_DIRRM_EXCLUDE');
$dirrm = array();

include_once "PEAR/Common.php";
$obj = &new PEAR_Common;
$info = $obj->infoFromAny("$WRKSRC/package.xml");

if (!empty($info['attribs']) && $info['attribs']['version'] == '2.0')
	$pkg = $info['name'];
else
	$pkg = $info['package'];

# output list of package files, in same order as specified in package
echo "$PEAR_LIB/.registry/".strtolower($pkg).".reg\n";
foreach($info['filelist'] as $f => $v) {
	switch($v['role']) {
	case 'test':
	case 'doc':
	case 'data':
		$prefix = "$v[role]/$pkg/";
		$dirrm["$v[role]/$pkg"] = true;
		break;

	case 'php':
	default:
		if (!empty($v['baseinstalldir']) && $v['baseinstalldir'] != '/') {
			$prefix = $v['baseinstalldir'] . '/';

			# sometimes the baseinstalldir begins with a slash,
			# which make the PLIST output to have two instead of
			# one.  We fix this here.
			if ($prefix[0] == '/')
				$prefix = substr($prefix, 1);

			if ($PEAR_DIRRM_BASEDIR)
				$dirrm[$v['baseinstalldir']] = true;
		} else
			$prefix = '';
		break;
	}

	# replace backslashes with forward slashes in the path name, for
	# pear packages written by non-UNIX oriented authors.
	$f = str_replace('\\', '/', $f);

	echo "{$PEAR_LIB}/{$prefix}{$f}\n";

	while(($f = dirname($f)) && $f != '.')
		$dirrm["{$prefix}{$f}"] = true;
}

# output @dirrm directives, in reverse order so that deeper
# directories are removed first
$dirrm = array_keys($dirrm);
rsort($dirrm);
foreach($dirrm as $dir) {
	$fulldir = "{$PEAR_LIB}/$dir";
	if ($PEAR_DIRRM_EXCLUDE && substr($fulldir, 0, strlen($PEAR_DIRRM_EXCLUDE)) == $PEAR_DIRRM_EXCLUDE)
		continue;
	echo "@dirrm $fulldir\n";
}
?>
