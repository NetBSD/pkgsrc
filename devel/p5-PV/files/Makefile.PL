# $NetBSD: Makefile.PL,v 1.2 2000/08/28 19:37:42 jlam Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'PV',
    'DISTNAME'  => 'PV.pm',
    'VERSION'   => '1.4',
    'linkext'   => { LINKTYPE=>'' },	# no link needed
    'dist'      => {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
