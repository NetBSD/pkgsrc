<?php //; echo; echo "YOU NEED TO RUN THIS SCRIPT WITH PHP NOW!"; echo; echo "Try this: lynx -source http://pear.php.net/go-pear | php -q"; echo; exit # -*- PHP -*-
# +----------------------------------------------------------------------+
# | PHP Version 5                                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 1997-2005 The PHP Group                                |
# +----------------------------------------------------------------------+
# | This source file is subject to version 2.02 of the PHP license,      |
# | that is bundled with this package in the file LICENSE, and is        |
# | available at through the world-wide-web at                           |
# | http://www.php.net/license/2_02.txt.                                 |
# | If you did not receive a copy of the PHP license and are unable to   |
# | obtain it through the world-wide-web, please send a note to          |
# | license@php.net so we can mail you a copy immediately.               |
# +----------------------------------------------------------------------+
# | Authors: Tomas V.V.Cox <cox@idecnet.com>                             |
# |          Stig Bakken <ssb@php.net>                                   |
# |          Christian Dickmann <dickmann@php.net>                       |
# |          Pierre-Alain Joye <pierre@php.net>                          |
# |          Greg Beaver <cellog@php.net>                                |
# +----------------------------------------------------------------------+
#
# $Id: go-pear.php,v 1.1.1.1 2007/05/05 21:21:47 adrianp Exp $
#
# Id: go-pear,v 1.104 2007/03/17 21:43:08 cellog Exp
#
# Automatically download all the files needed to run the "pear" command
# (the PEAR package installer).  Requires PHP 4.1.0 or newer.
#
# Installation: Linux
#
# This script can either be directly launched or passed via lynx like this.
#
#  $ lynx -source http://pear.php.net/go-pear | php
#
# The above assumes your php binary is named php and that it's
# executable through your PATH:
#
# Installation: Windows
#
# On Windows, go-pear uses stdin for user input, so you must download
# go-pear first and then run it:
#
# Note: In PHP 4.2.0-4.2.3, the PHP CLI binary is named php-cli.exe while since
# PHP 4.3.0, it's simply named php.exe in the cli/ folder of your PHP directory.
# The CGI is also named php.exe but it sits directly in your PHP directory.
#
#  > cli/php -r "readfile('http://pear.php.net/go-pear');" > go-pear
#  > cli/php go-pear
#
# In PHP 5.0.0+, the PHP CLI binary is php.exe
#
#  > php -r "readfile('http://pear.php.net/go-pear');" > go-pear
#  > php go-pear
#
# Installation: Notes
#
# - If using the CGI version of PHP, append the -q option to suppress
#   headers in the output.
# - By default, go-pear will install a system-wide configuration file.  For
#   a local install use:
#   > php go-pear local
#
# - Once the go-pear script is initiated, you will see instructions on
#   how to continue installing PEAR.  The first thing you should see is:
#
#   Welcome to go-pear!
#
# Installation: Web browser
#
# You can now use go-pear via a webbrowser, thanks to Christian Dickmann. It is
# still beta codes, but feel free to test it:
# 1.: Download the go-pear script by using the "Save target as ..." function
# of your browser here.
#
# 2.: Place the go-pear file somewhere under the document root of your webserver.
# The easiest way is to create a new directory for pear and to put the file in there.
# Be sure your web server is setup to recognize PHP, and that you use an appropriate
# extension.  For example, you might name this file gopear.php
#
# 3.: Access go-pear through your webserver and follow the instructions. Please
# make sure that PHP has write access to the dir you want to install PEAR into.
# For example: http://localhost/pear/gopear.php
#
# 4.: After running go-pear you get a link to the Web Frontend of the PEAR installer.
# I suggest bookmarking this link.
#
# 5.: Protect the Web Frontend directory and the go-pear script with a password.
# Use .htaccess on Apache webservers for example.
#
#
function dump($var) {
    if (defined('WEBINSTALLER') && WEBINSTALLER == 'cgi') {
        echo '<pre>';
        print_r($var);
        echo '</pre>';
    } else {
        print_r($var);
        echo "\n";
    }
}

$sapi_name = php_sapi_name();

$safe_mode = (bool)ini_get('safe_mode');
if (!$safe_mode) {
    set_time_limit(0);
}



@ob_end_clean();
ob_implicit_flush(true);
define('WEBINSTALLER', ($sapi_name != 'cli' && !(substr($sapi_name,0,3)=='cgi' && !isset($_SERVER['GATEWAY_INTERFACE']))));

ini_set('track_errors', true);
ini_set('html_errors', WEBINSTALLER);
ini_set('magic_quotes_runtime', false);
error_reporting( E_ALL & ~E_NOTICE);

define('WINDOWS', (substr(PHP_OS, 0, 3) == 'WIN'));
define('GO_PEAR_VER', '0.6.0');

if (!function_exists('file_get_contents')) {
    function file_get_contents($filename)
    {
        $fp = fopen($filename, 'rb');
        $ret = '';
        while (!feof($fp)) {
            $ret .= fread($fp, 8092);;
        }
        return $ret;
    }
}

define('WIN32GUI', !WEBINSTALLER && WINDOWS && $sapi_name=='cli' && which('cscript'));

/*
 * See bug #23069
 */
if ( WEBINSTALLER && WINDOWS ) {
    $php_sapi_name = win32DetectPHPSAPI();
    if($php_sapi_name=='cgi'){
    $msg = nl2br("
Sorry! The PEAR installer actually does not work on Windows platform using CGI and Apache.
Please install the module SAPI (see http://www.php.net/manual/en/install.apache.php for the
instructions) or use the CLI (cli\php.exe) in the console.
");
        displayHTML('error', $msg);
    }
}

if (WEBINSTALLER && isset($_GET['action']) && $_GET['action'] == 'img' && isset($_GET['img'])) {
    switch ($_GET['img'])
    {
        case 'note':
        case 'pearlogo':
        case 'smallpear':
            showImage($_GET['img']);
            exit;
        default:
            exit;
    };
}

// Check if PHP version is sufficient
if (function_exists("version_compare") && version_compare(phpversion(), "4.2.0",'<')) {
    die("Sorry!  Your PHP version is too old.  PEAR and this script requires at
least PHP 4.2.0 for stable operation.

It may be that you have a newer version of PHP installed in your web
server, but an older version installed as the 'php' command.  In this
case, you need to rebuilt PHP from source.

If your source is 4.2.x, you need to run 'configure' with the
--enable-cli option, rebuild and copy sapi/cli/php somewhere.

If your source is 4.3.x or newer, just make sure you don't run
'configure' with --disable-cli, rebuilt and copy sapi/cli/php.

Please upgrade PHP to a newer version, and try again.  See you then.

");
}

$installer_packages = array(
    'PEAR-stable',
    'Archive_Tar-stable',
    'Console_Getopt-stable',
    'Structures_Graph-stable',
    );

if (WEBINSTALLER) {
    $installer_packages[] = 'HTML_Template_IT-stable';
    $installer_packages[] = 'Net_UserAgent_Detect-stable';
    $installer_packages[] = 'PEAR_Frontend_Web-alpha';
}

$pfc_packages = array(
    'MDB2',
);

$config_desc = array(
    'prefix' => 'Installation prefix',
    'bin_dir' => 'Binaries directory',
    'php_dir' => 'PHP code directory ($php_dir)',
    'doc_dir' => 'Documentation base directory',
    'data_dir' => 'Data base directory',
    'test_dir' => 'Tests base directory',
    'temp_dir' => 'Temporary files directory'
);

if(!WEBINSTALLER && WINDOWS){
    $config_desc['php_bin'] = 'php.exe path';
}

if (WEBINSTALLER) {
    $config_desc['cache_dir'] = 'PEAR Installer cache directory';
    $config_desc['cache_ttl'] = 'Cache TimeToLive';
    $config_desc['webfrontend_file'] = 'Filename of WebFrontend';
    $config_desc['php_bin'] = "php.exe path, optional (CLI command tools)";
}

if (my_env('HTTP_PROXY')) {
    $http_proxy = my_env('HTTP_PROXY');
} elseif (my_env('http_proxy')) {
    $http_proxy = my_env('http_proxy');
} else {
    $http_proxy = '';
}

register_shutdown_function('bail');

detect_install_dirs();

if (WEBINSTALLER) {
    @session_start();

    /*
        See bug #23069
    */
    if ( WINDOWS ) {
        $php_sapi_name = win32DetectPHPSAPI();
        if($php_sapi_name=='cgi'){
            $msg = "
    Sorry! The PEAR installer actually does not work on Windows platform using CGI and Apache.
    Please install the module SAPI (see http://www.php.net/manual/en/install.apache.php for the
    instructions) or use the CLI (cli\php.exe) in the console.
    ";
            displayHTML('error', $msg);
            exit();
        }
    }

    if (!isset($_SESSION['go-pear']) || isset($_GET['restart'])) {
        $_SESSION['go-pear'] = array(
            'http_proxy' => $http_proxy,
            'config' => array(
                'prefix'    => dirname(__FILE__),
                'bin_dir'   => $bin_dir,
                'php_bin'   => $php_bin,
                'php_dir'   => '$prefix/PEAR',
                'doc_dir'   => $doc_dir,
                'data_dir'  => $data_dir,
                'test_dir'  => $test_dir,
                'temp_dir'   => '$prefix/temp',
                'cache_dir' => '$php_dir/cache',
                'cache_ttl' => 300,
                'webfrontend_file' => '$prefix/index.php',
                ),
            'install_pfc' => true,
            'DHTML' => true,
            );
    }

    if (!isset($_GET['step'])) {
        $_GET['step'] = 'Welcome';
        /* clean up old sessions datas */
        session_destroy();
    }
    if ($_GET['step'] == 'install') {
        $_SESSION['go-pear']['http_proxy'] = strip_magic_quotes($_POST['proxy']['host']).':'.strip_magic_quotes($_POST['proxy']['port']);
        if ($_SESSION['go-pear']['http_proxy'] == ':') {
            $_SESSION['go-pear']['http_proxy'] = '';
        };

        $www_errors = array();
        foreach($_POST['config'] as $key => $value) {
            $_POST['config'][$key] = strip_magic_quotes($value);
            if($key!='cache_ttl'){
                if ( empty($_POST['config'][$key]) ) {
                    if (WEBINSTALLER && $key!='php_bin' ) {
                        $www_errors[$key] = 'Please fill this path, you can use $prefix, $php_dir or a full path.';
                    }
                }
            }
        }

        if( sizeof($www_errors)>0){
            $_GET['step'] = 'config';
        }

        $_SESSION['go-pear']['config'] = $_POST['config'];
        $_SESSION['go-pear']['install_pfc'] = (isset($_POST['install_pfc']) && $_POST['install_pfc'] == 'on');
        $_SESSION['go-pear']['DHTML'] = isset($_POST['BCmode']) ? false : true;
    }

    $http_proxy = $_SESSION['go-pear']['http_proxy'];
    foreach($_SESSION['go-pear']['config'] as $var => $value) {
        $$var = $value;
    }
    $install_pfc = $_SESSION['go-pear']['install_pfc'];
}

if (!WEBINSTALLER) {
    $tty = WINDOWS ? @fopen('\con', 'r') : @fopen('/dev/tty', 'r');

    if (!$tty) {
        $tty = fopen('php://stdin', 'r');
    }

    $local = isset($_SERVER['argv'][1]) && $_SERVER['argv'][1] == 'local';
    if ($local) {
        $local = "
Running in local install mode
";
    } elseif (WINDOWS) {
        $local = "
Use 'php " . $_SERVER['argv'][0] . " local' to install a local copy of PEAR.
";
    }
    print "Welcome to go-pear!

Go-pear will install the 'pear' command and all the files needed by
it.  This command is your tool for PEAR installation and maintenance.
$local
Go-pear also lets you download and install the PEAR packages bundled
with PHP: " . implode(', ', $pfc_packages) . ".


If you wish to abort, press Control-C now, or press Enter to continue: ";

    fgets($tty, 1024);

    print "\n";

        print "HTTP proxy (http://user:password@proxy.myhost.com:port), or Enter for none:";

    if (!empty($http_proxy)) {
        print " [$http_proxy]";
    }
    print ": ";
    $tmp = trim(fgets($tty, 1024));
    if (!empty($tmp)) {
        $http_proxy = $tmp;
    }
}

$origpwd = getcwd();

$config_vars = array_keys($config_desc);

// make indices run from 1...
array_unshift($config_vars, "");
unset($config_vars[0]);
reset($config_vars);
$desclen = max(array_map('strlen', $config_desc));
$descfmt = "%-{$desclen}s";
$first = key($config_vars);
end($config_vars);
$last = key($config_vars);

if (WEBINSTALLER) {
    if ( isset($www_errors) && sizeof($www_errors) ) {
        displayHTML('config');
        exit();
    } else {
        if (isset($_SESSION['go-pear']['DHTML']) && $_SESSION['go-pear']['DHTML'] == true && $_GET['step'] == 'install') {
            $_GET['step'] = 'preinstall';
        }
        if ($_GET['step'] != 'install' && $_GET['step'] != 'install-progress') {
            displayHTML($_GET['step']);
            exit;
        }
        if ($_GET['step'] == 'install-progress') {
            displayHTMLHeader();
            echo "Starting installation ...<br/>";
        }
        ob_start();
    }
}

$progress = 0;

/*
 * Checks PHP SAPI version under windows/CLI
 */
if( WINDOWS && !WEBINSTALLER && $php_bin=='') {
    print "
We do not find any php.exe, please select the php.exe folder (CLI is
recommanded, usually in c:\php\cli\php.exe)
";
    $php_bin_set = false;
} elseif ( WINDOWS && !WEBINSTALLER && strlen($php_bin) ) {
    $php_bin_sapi = win32DetectPHPSAPI();
    $php_bin_set = true;
    switch($php_bin_sapi){
        case 'cli':
        break;
        case 'cgi':
            print "
*NOTICE*
We found php.exe under $php_bin, it uses a $php_bin_sapi SAPI. PEAR commandline
tool works well with it, if you have a CLI php.exe available, we
recommand to use it.
";
        break;
        default:
            print "
*WARNING*
We found php.exe under $php_bin, it uses an unknown SAPI. PEAR commandline
tool has not been tested with it, if you have a CLI (or CGI) php.exe available,
we strongly recommand to use it.

";
        break;
    }
}

while (!WEBINSTALLER) {
    print "
Below is a suggested file layout for your new PEAR installation.  To
change individual locations, type the number in front of the
directory.  Type 'all' to change all of them or simply press Enter to
accept these locations.

";

    foreach ($config_vars as $n => $var) {
        printf("%2d. $descfmt : %s\n", $n, $config_desc[$var], $$var);
    }

    print "\n$first-$last, 'all' or Enter to continue: ";
    $tmp = trim(fgets($tty, 1024));
    if ( empty($tmp) ) {
        if( WINDOWS && !$php_bin_set ){
            echo "**ERROR**
Please, enter the php.exe path.

";
        } else {
            break;
        }
    }
    if (isset($config_vars[(int)$tmp])) {
        $var = $config_vars[(int)$tmp];
        $desc = $config_desc[$var];
        $current = $$var;

        if(WIN32GUI){
            $tmp = win32BrowseForFolder("$desc [$current] :");
        } else {
            print "$desc [$current] : ";
            $tmp = trim(fgets($tty, 1024));
        }

        $old = $$var;
        if(WINDOWS && $var=='php_bin' ){
            if(file_exists($tmp.DIRECTORY_SEPARATOR.'php.exe')){
                $tmp = $tmp.DIRECTORY_SEPARATOR.'php.exe';
                $php_bin_sapi = win32DetectPHPSAPI();
                if($php_bin_sapi=='cgi'){
            print "
******************************************************************************
NOTICE! We found php.exe under $php_bin, it uses a $php_bin_sapi SAPI.
PEAR commandline tool works well with it.
If you have a CLI php.exe available, we recommand to use it.

";
                } elseif ($php_bin_sapi=='unknown') {
            print "
******************************************************************************
WARNING! We found php.exe under $php_bin, it uses an $php_bin_sapi SAPI.
PEAR commandline tool has not been tested with it.
If you have a CLI (or CGI) php.exe available, we strongly recommand to use it.

";
                }
                echo "php.exe (sapi: $php_bin_sapi) found.\n\n";
                $php_bin_set = true;
            } else {
                echo "**ERROR**: no php.exe found in this folder.\n";
                $tmp='';
            }
        }

        if (!empty($tmp) ) {
            $$var = $tmp;
        }
    } elseif ($tmp == 'all') {
        foreach ($config_vars as $n => $var) {
            $desc = $config_desc[$var];
            $current = $$var;
            print "$desc [$current] : ";
            $tmp = trim(fgets($tty, 1024));
            if (!empty($tmp)) {
                $$var = $tmp;
            }
        }
    }
}

foreach ($config_vars as $n => $var) {
    for ($m = 1; $m <= count($config_vars); $m++) {
        $var2 = $config_vars[$m];
        $$var = str_replace('$'.$var2, $$var2, $$var);
    }
}


####
# Temp stuff
####
if (!empty($temp_dir)) {
    $_found = temp_dir($temp_dir);
} else {
    $_found = temp_dir();
}

if (!$_found) {
            print "

******************************************************************************
FATAL ERROR! We cannot initialize the temp directory. Please be sure to give
full write access to this directory and the install directory.

";

    if (!empty($temp_dir)) {
        print "'$temp_dir' was given.";
    }
    exit();
}

$foo = $ptmp;

$ptmp = tempnam($ptmp, 'gope');

if (WINDOWS) {
    $ptmp = str_replace($foo,'',$ptmp);
    $foo = str_replace("\\\\",'/',$foo);
    $s = substr($ptmp,0,1);
    if($s == "\\" || $s == '/' ){
        $ptmp = $foo . '/' . substr($ptmp,1);
    } else {
        $ptmp = $foo . '/' . $ptmp;
    }
}

rm_rf($ptmp);
mkdir_p($ptmp, 0700);
$ok = @chdir($ptmp);

foreach ($config_vars as $var) {
    $dir = $$var;

    if (!preg_match('/_dir$/', $var)) {
        continue;
    }

    if (!@is_dir($dir)) {
        if (!mkdir_p($dir)) {
            $root = WINDOWS ? 'administrator' : 'root';
            bail("Unable to create {$config_desc[$var]} $dir.
Run this script as $root or pick another location.\n");
        }
    }
}

if (!WEBINSTALLER) {
    $msg = "The following PEAR packages are bundled with PHP: " .
        implode(', ', $pfc_packages);
    print "\n" . wordwrap($msg, 75) . ".\n";
    print "Would you like to install these as well? [Y/n] : ";
    $install_pfc = !stristr(fgets($tty, 1024), "n");
    print "\n";
}

####
# Download
####

if (function_exists('set_include_path')) {
   set_include_path($ptmp);
} else {
   ini_set('include_path', $ptmp);
}

if (!extension_loaded('zlib') && !WEBINSTALLER) { // In Web context we could be in multithread env which makes dl() end up with a fatal error.
    if (WINDOWS) {
        @dl('php_zlib.dll');
    } elseif (PHP_OS == 'HP-UX') {
        @dl('zlib.sl');
    } elseif (PHP_OS == 'AIX') {
        @dl('zlib.a');
    } else {
        @dl('zlib.so');
    }
}
if (!extension_loaded('zlib')) {
    $urltemplate = 'http://pear.php.net/get/%s?uncompress=yes';
    $have_gzip = null;
} else {
    $urltemplate = 'http://pear.php.net/get/%s';
    $have_gzip = true;
}

print "Loading zlib: ".($have_gzip ? 'ok' : 'failed')."\n";

if (!$have_gzip) {
    print "Downloading uncompressed packages\n";
};

if ($install_pfc) {
    $to_install = array_merge($installer_packages, $pfc_packages);
} else {
    $to_install = $installer_packages;
}

displayHTMLProgress($progress = 5);

if (file_exists(dirname(__FILE__).'/go-pear-bundle') || is_dir(dirname(__FILE__).'/go-pear-bundle')) {
    $dh = @opendir(dirname(__FILE__).'/go-pear-bundle');
} else {
    $dh = false;
}

$local_dir = array();
if ($dh) {
    while($file = @readdir($dh)) {
        if ($file == '.' || $file == '..' || !is_file(dirname(__FILE__).'/go-pear-bundle/'.$file)) {
            continue;
        }
        $_pos = strpos($file, '-');
        if ($_pos === false) {
          $local_dir[$file] = $file;
        } else {
          $local_dir[substr($file, 0, $_pos)] = $file;
        }
    }
}

foreach ($installer_packages as $pkg) {
    $pkg_basename = substr($pkg, 0, strpos($pkg, '-'));
    if (isset($local_dir[$pkg_basename])) {
        echo str_pad("Using local package: $pkg", max(38,21+strlen($pkg)+4), '.');
        copy(dirname(__FILE__) . '/go-pear-bundle/' . $local_dir[$pkg_basename], $local_dir[$pkg_basename]);
        $tarball[$pkg_basename] = $local_dir[$pkg_basename];
        echo "ok\n";
        displayHTMLProgress($progress += round(65 / count($to_install)));
        continue;
    }

    $msg = str_pad("Downloading package: $pkg", max(38,21+strlen($pkg)+4), '.');
    print $msg;
    $url = sprintf($urltemplate, $pkg);

    $pkg = str_replace('-stable', '', $pkg);

    $tarball[$pkg] = download_url($url, null, $http_proxy);
    print "ok\n";
    displayHTMLProgress($progress += round(65 / count($to_install)));
}

print 'Bootstrapping: PEAR...................';
if (in_array('PEAR.php', $local_dir)) {
    copy(dirname(__FILE__).'/go-pear-bundle/PEAR.php', 'PEAR.php');
    echo "(local) ";
} else {
    $url = 'http://cvs.php.net/viewcvs.cgi/pear-core/PEAR.php?view=co&pathrev=PEAR_1_4';
    echo "(remote) ";
    download_url($url, 'PEAR.php', $http_proxy);
}

include_once 'PEAR.php';
print "ok\n";

print 'Bootstrapping: Archive_Tar............';
$r = 'RELEASE_' . ereg_replace('[^A-Za-z0-9]', '_', substr(substr($tarball['Archive_Tar'], 12), 0, -4));

/* force to a known revision */
$url = "http://cvs.php.net/viewcvs.cgi/pear/Archive_Tar/Archive/Tar.php?view=co&pathrev=RELEASE_1_3_2";
mkdir('Archive', 0700);

if (in_array('Tar.php', $local_dir)) {
    copy(dirname(__FILE__).'/go-pear-bundle/Tar.php', 'Archive/Tar.php');
    echo "(local) ";
} else {
    download_url($url, 'Archive/Tar.php', $http_proxy);
    echo "(remote) ";
}
print "ok\n";

print 'Bootstrapping: Console_Getopt.........';
$r = 'RELEASE_' . ereg_replace('[^A-Za-z0-9]', '_', substr(substr($tarball['Console_Getopt'], 15), 0, -4));
$url = "http://cvs.php.net/viewcvs.cgi/pear-core/Console/Getopt.php?view=co&pathrev=PEAR_1_4";
mkdir('Console', 0700);
if (in_array('Getopt.php', $local_dir)) {
    copy(dirname(__FILE__).'/go-pear-bundle/Getopt.php', 'Console/Getopt.php');
    echo "(local) ";
} else {
    download_url($url, 'Console/Getopt.php', $http_proxy);
    echo "(remote) ";
}
print "ok\n";

if ($install_pfc) {
    foreach ($pfc_packages as $pkg) {
        foreach($local_dir as $file) {
            if (substr($file, 0, strlen($pkg)) == $pkg) {
                echo str_pad("Using local package: $pkg", max(38,21+strlen($pkg)+4), '.');
                copy(dirname(__FILE__).'/go-pear-bundle/'.$file, $file);
                $tarball[$pkg] = $file;
                echo "ok\n";
                displayHTMLProgress($progress += round(65 / count($to_install)));
                continue 2;
            };
        };

        $msg = str_pad("Downloading package: $pkg", max(38,21+strlen($pkg)+4), '.');
        print $msg;
        $url = sprintf($urltemplate, $pkg);
        $tarball[$pkg] = download_url($url, null, $http_proxy);
        print "ok\n";
        displayHTMLProgress($progress += round(65 / count($to_install)));
    }
}

displayHTMLProgress($progress = 70);

PEAR::setErrorHandling(PEAR_ERROR_DIE, "\n%s\n");
print 'Extracting installer..................';

$dot = strrpos($tarball['Structures_Graph'], '.');
$pkg = substr($tarball['Structures_Graph'], 0, $dot);
$ext = substr($tarball['Structures_Graph'], $dot + 1);

include_once 'Archive/Tar.php';

$tar = &new Archive_Tar($tarball['Structures_Graph'], $have_gzip);
if (!$tar->extractModify($ptmp, $pkg)) {
    bail("failed!\n");
}

$dot = strrpos($tarball['PEAR'], '.');
$pkg = substr($tarball['PEAR'], 0, $dot);
$ext = substr($tarball['PEAR'], $dot + 1);

$tar = &new Archive_Tar($tarball['PEAR'], $have_gzip);
if (!$tar->extractModify($ptmp, $pkg)) {
    bail("failed!\n");
}
print "ok\n";

$tarball['PEAR'] = 'package.xml'; // :-)

// Default for sig_bin
putenv('PHP_PEAR_SIG_BIN=""');
// Default for sig_keydir
putenv('PHP_PEAR_SIG_KEYDIR=""');
putenv('PHP_PEAR_DOWNLOAD_DIR=' . $temp_dir . '/download');
putenv('PHP_PEAR_TEMP_DIR=' . $temp_dir);

include_once "PEAR.php";
include_once "PEAR/Config.php";
include_once "PEAR/Command.php";
include_once "PEAR/Registry.php";

if (WEBINSTALLER || isset($_SERVER['argv'][1]) && $_SERVER['argv'][1] == 'local') {
    $config = &PEAR_Config::singleton($prefix."/pear.conf", '');
} else {
    $config = &PEAR_Config::singleton();
}


$config->set('preferred_state', 'stable');
foreach ($config_vars as $var) {
    $config->set($var, $$var);
}
$config->set('download_dir', $temp_dir . '/download');
$config->set('temp_dir', $temp_dir);
$config->store();

$registry = new PEAR_Registry($php_dir);
PEAR_Command::setFrontendType('CLI');
$install = &PEAR_Command::factory('install', $config);

$install_options = array(
    'nodeps' => true,
    'force' => true,
);

foreach ($tarball as $pkg => $src) {
    $options = $install_options;
    if ($registry->packageExists($pkg)) {
        $options['upgrade'] = true;
    }

    $install->run('install', $options, array($src));

    displayHTMLProgress($progress += round(29 / count($tarball)));
}

displayHTMLProgress($progress = 99);

// Base installation finished

ini_restore("include_path");

if (!WEBINSTALLER) {
    $sep = WINDOWS ? ';' : ':';
    $include_path = explode($sep, ini_get('include_path'));
    if (WINDOWS) {
        $found = false;
        $t = strtolower($php_dir);
        foreach($include_path as $path) {
            if ($t==strtolower($path)) {
                $found = true;
                break;
            }
        }
    } else {
        $found = in_array($php_dir, $include_path);
    }
    if (!$found) {
        print "
******************************************************************************
WARNING!  The include_path defined in the currently used php.ini does not
contain the PEAR PHP directory you just specified:
<$php_dir>
If the specified directory is also not in the include_path used by
your scripts, you will have problems getting any PEAR packages working.
";

        if ( $php_ini = getPhpiniPath() ) {
            print "\n\nWould you like to alter php.ini <$php_ini>? [Y/n] : ";
            $alter_phpini = !stristr(fgets($tty, 1024), "n");
            if( $alter_phpini ) {
                alterPhpIni($php_ini);
            } else {
                if (WINDOWS) {
                    print "
Please look over your php.ini file to make sure
$php_dir is in your include_path.";
                } else {
                    print "
I will add a workaround for this in the 'pear' command to make sure
the installer works, but please look over your php.ini or Apache
configuration to make sure $php_dir is in your include_path.
";
                }

            }
        }

    print "
Current include path           : ".ini_get('include_path')."
Configured directory           : $php_dir
Currently used php.ini (guess) : $php_ini
";

        print "Press Enter to continue: ";
        fgets($tty, 1024);
    }

    $pear_cmd = $bin_dir . DIRECTORY_SEPARATOR . 'pear';
    $pear_cmd = WINDOWS ? strtolower($pear_cmd).'.bat' : $pear_cmd;

    // check that the installed pear and the one in tha path are the same (if any)
    $pear_old = which(WINDOWS ? 'pear.bat' : 'pear', $bin_dir);
    if ($pear_old && ($pear_old != $pear_cmd)) {
        // check if it is a link or symlink
        $islink = WINDOWS ? false : is_link($pear_old) ;
        if ($islink && readlink($pear_old) != $pear_cmd) {
            print "\n** WARNING! The link $pear_old does not point to the " .
                  "installed $pear_cmd\n";
        } elseif (is_writable($pear_old) && !is_dir($pear_old)) {
            rename($pear_old, "{$pear_old}_old");
            print "\n** WARNING! Backed up old pear to {$pear_old}_old\n";
        } else {
            print "\n** WARNING! Old version found at $pear_old, please remove it or ".
                  "be sure to use the new $pear_cmd command\n";
        }
    }

    print "\nThe 'pear' command is now at your service at $pear_cmd\n";

    // Alert the user if the pear cmd is not in PATH
    $old_dir = $pear_old ? dirname($pear_old) : false;
    if (!which('pear', $old_dir)) {
        print "
** The 'pear' command is not currently in your PATH, so you need to
** use '$pear_cmd' until you have added
** '$bin_dir' to your PATH environment variable.

";

    print "Run it without parameters to see the available actions, try 'pear list'
to see what packages are installed, or 'pear help' for help.

For more information about PEAR, see:

  http://pear.php.net/faq.php
  http://cvs.php.net/co.php/pearweb/doc/pear_package_manager.txt?p=1
  http://pear.php.net/manual/

Thanks for using go-pear!

";
    }
}

if (WEBINSTALLER) {
    print "Writing WebFrontend file ... ";
    @unlink($webfrontend_file); //Delete old one
    copy ( $doc_dir.DIRECTORY_SEPARATOR.
            'PEAR_Frontend_Web'.DIRECTORY_SEPARATOR.
            'docs'.DIRECTORY_SEPARATOR.
            'example.php',
            $webfrontend_file
        );
    if ($_GET['step'] == 'install-progress') {
        displayHTMLProgress($progress = 100);
        ob_end_clean();
        displayHTMLInstallationSummary();
        displayHTMLFooter();
    } else {
        $out = ob_get_contents();

        $out = explode("\n", $out);
        foreach($out as $line => $value) {
            if (preg_match('/ok$/', $value)) {
                $value = preg_replace('/(ok)$/', '<span class="green">\1</span>', $value);
            };
            if (preg_match('/^install ok:/', $value)) {
                $value = preg_replace('/^(install ok:)/', '<span class="green">\1</span>', $value);
            };
            if (preg_match('/^Warning:/', $value)) {
                $value = '<span style="color: #ff0000">'.$value.'</span>';
            };
            $out[$line] = $value;
        };
        $out = nl2br(implode("\n",$out));
        ob_end_clean();

        displayHTML('install', $out);
    }
    // Little hack, this will be fixed in PEAR later
    if ( WINDOWS ) {
        clearstatcache();
        @unlink($bin_dir.DIRECTORY_SEPARATOR.'.tmppear');
    }
    exit;
}

// Little hack, this will be fixed in PEAR later
if ( WINDOWS ) {
    clearstatcache();
    @unlink($bin_dir.DIRECTORY_SEPARATOR.'.tmppear');
}

if (WINDOWS && !WEBINSTALLER) {
    win32CreateRegEnv();
}
// Set of functions following

// {{{ download_url()

function download_url($url, $destfile = null, $proxy = null)
{
    $use_suggested_filename = ($destfile === null);
    if ($use_suggested_filename) {
        $destfile = basename($url);
    }
    $tmp = parse_url($url);
    if (empty($tmp['port'])) {
        $tmp['port'] = 80;
    }
    if (empty($proxy)) {
        $fp = fsockopen($tmp['host'], $tmp['port'], $errno, $errstr);
        //print "\nconnecting to $tmp[host]:$tmp[port]\n";
    } else {
        $tmp_proxy = parse_url($proxy);
        $phost     = $tmp_proxy['host'];
        $pport     = $tmp_proxy['port'];
        $fp = fsockopen($phost, $pport, $errno, $errstr);
        //print "\nconnecting to $phost:$pport\n";
    }
    if (!$fp) {
        bail("download of $url failed: $errstr ($errno)\n");
    }
    if (empty($proxy)) {
        $path = $tmp['path'];
    } else {
        $path = "http://$tmp[host]:$tmp[port]$tmp[path]";
    }
    if (isset($tmp['query'])) {
        $path .= "?$tmp[query]";
    }
    if (isset($tmp['fragment'])) {
        $path .= "#$tmp[fragment]";
    }
    $request = "GET $path HTTP/1.0\r\nHost: $tmp[host]:$tmp[port]\r\n".
        "User-Agent: go-pear\r\n";

    if (!empty($proxy) && $tmp_proxy['user'] != '') {
        $request .= 'Proxy-Authorization: Basic ' .
                    base64_encode($tmp_proxy['user'] . ':' . $tmp_proxy['pass']) . "\r\n";
    }
    $request .= "\r\n";
    fwrite($fp, $request);
    $cdh = "content-disposition:";
    $cdhl = strlen($cdh);
    $content_length = 0;
    while ($line = fgets($fp, 2048)) {
        if (trim($line) == '') {
            break;
        }
        if (preg_match('/^Content-Length: (.*)$/i', $line, $matches)) {
            $content_length = trim($matches[1]);
        }
        if ($use_suggested_filename && !strncasecmp($line, $cdh, $cdhl)) {
            if (eregi('filename="([^"]+)"', $line, $matches)) {
                $destfile = basename($matches[1]);
            }
        }
    }

    if ($content_length) {
        displayHTMLSetDownload($destfile);
    };
    $wp = fopen($destfile, "wb");
    if (!$wp) {
        bail("could not open $destfile for writing\n");
    }
    $bytes_read = 0;
    $progress = 0;
    while ($data = fread($fp, 2048)) {
        fwrite($wp, $data);
        $bytes_read += strlen($data);
        if ($content_length != 0 && floor($bytes_read * 10 / $content_length) != $progress) {
            $progress = floor($bytes_read * 10 / $content_length);
            displayHTMLDownloadProgress($progress * 10);
        };
    }
    fclose($fp);
    fclose($wp);
    return $destfile;
}

// }}}
// {{{ which()

function which($program, $dont_search_in = false)
{
    if (WINDOWS) {
        if ($_path=my_env('Path')) {
            $dirs = explode(';', $_path);
        } else {
            $dirs = explode(';', my_env('PATH'));
        }
        foreach ($dirs as $i => $dir) {
            $dirs[$i] = strtolower(realpath($dir));
        }
        if ($dont_search_in) {
            $dont_search_in = strtolower(realpath($dont_search_in));
        }
        if ($dont_search_in &&
            ($key = array_search($dont_search_in, $dirs)) !== false)
        {
            unset($dirs[$key]);
        }

        foreach ($dirs as $dir) {
            $dir = str_replace('\\\\', '\\', $dir);
            if (!strlen($dir)) {
                continue;
            }
            if ($dir{strlen($dir) - 1} != '\\') {
                $dir .= '\\';
            }
            $tmp = $dir . $program;
            $info = pathinfo($tmp);
            if (in_array(strtolower($info['extension']),
                  array('exe', 'com', 'bat', 'cmd'))) {
                if (file_exists($tmp)) {
                    return strtolower($tmp);
                }
            } elseif (file_exists($ret = $tmp . '.exe') ||
                file_exists($ret = $tmp . '.com') ||
                file_exists($ret = $tmp . '.bat') ||
                file_exists($ret = $tmp . '.cmd')) {
                return strtolower($ret);
            }
        }
    } else {
        $dirs = explode(':', my_env('PATH'));
        if ($dont_search_in &&
            ($key = array_search($dont_search_in, $dirs)) !== false)
        {
            unset($dirs[$key]);
        }
        foreach ($dirs as $dir) {
            if (is_executable("$dir/$program")) {
                return "$dir/$program";
            }
        }
    }
    return false;
}

// }}}
// {{{ bail()

function bail($msg = '')
{
    global $ptmp, $origpwd;
    if ($ptmp && is_dir($ptmp)) {
        chdir($origpwd);
        rm_rf($ptmp);
    }
    if ($msg && WEBINSTALLER) {
        $msg = @ob_get_contents() ."\n\n". $msg;
        @ob_end_clean();
        displayHTML('error', $msg);
        exit;
    };
    if ($msg && !WEBINSTALLER) {
        die($msg);
    }
}

// }}}
// {{{ mkdir_p()

function mkdir_p($dir, $mode = 0777)
{
    if (@is_dir($dir)) {
        return true;
    }

    $parent = dirname($dir);
    $ok = true;
    if (!@is_dir($parent) && $parent != $dir) {
        $ok = mkdir_p(dirname($dir), $mode);
    }
    if ($ok) {
        $ok = @mkdir($dir, $mode);
        if (!$ok) {
            print "mkdir failed: <$dir>\n";
        }
    }
    return $ok;
}

// }}}
// {{{ rm_rf()

function rm_rf($path)
{
    if (@is_dir($path) && is_writable($path)) {
        $dp = opendir($path);
        while ($ent = readdir($dp)) {
            if ($ent == '.' || $ent == '..') {
                continue;
            }
            $file = $path . DIRECTORY_SEPARATOR . $ent;
            if (@is_dir($file)) {
                rm_rf($file);
            } elseif (is_writable($file)) {
                unlink($file);
            } else {
                echo $file . "is not writable and cannot be removed.
Please fix the permission or select a new path.\n";
            }
        }
        closedir($dp);
        return rmdir($path);
    } else {
        return @unlink($path);
    }
}

// }}}
// {{{ tmpdir()
/*
 * Fixes for winXP/wrong tmp set by Urs Gehrig (urs@circle.ch)
 */
function temp_dir($default=false)
{
    global $ptmp, $prefix;

    if ($default) {
         if (!@is_dir($default)) {
            if (!mkdir_p($default)) {
                return false;
            }
        }

        /* try it really, is_writable is buggy with openbasedir */
        $fh = fopen(realpath($default) . "/test","wb");
        if ($fh) {
            $ptmp = $default;
            return true;
        } else {
            $ptmp = "failed";
            return false;
        }
    }

    $_temp = false;
    if (WINDOWS){
        if ( my_env('TEMP') ) {
            $_temp = my_env('TEMP');
        } elseif ( my_env('TMP') ) {
            $_temp = my_env('TMP');
        } elseif ( my_env('windir') ) {
            $_temp = my_env('windir') . '\temp';
        } elseif ( my_env('SystemRoot') ) {
            $_temp = my_env('SystemRoot') . '\temp';
        }

        // handle ugly ENV var like \Temp instead of c:\Temp
        $dirs = explode("\\", realpath($_temp));
        if(strpos($_temp, ":") != 1) {
            unset($_temp);
            $_dirs = array();
            foreach($dirs as $val) {
                if((boolean)$val ) {
                    $_dirs[] = str_replace("/", "",  $val);
                }
            }
            unset($dirs);
            $dirs = $_dirs;
            array_unshift ($dirs, "c:" );
            $_temp = $dirs[0];
            for($i = 1;$i < count($dirs);$i++) {
                $_temp .= "//" . $dirs[$i];
            }
        }
        $ptmp = $_temp;
    } else {
        $_temp = my_env('TMPDIR');
        if (!$_temp) {
            if (is_writable('/tmp')) {
                $_temp = '/tmp';
            }
        }
    }

    // If for some reason the user has no rights to access to
    // the standard tempdir, we assume that he has the right
    // to access his prefix and choose $prefix/tmp as tempdir
    if (!$_temp) {
        print "System's Tempdir failed, trying to use \$prefix/tmp ...";
        $res = mkdir_p($prefix.'/tmp');
        if (!$res) {
            bail('mkdir '.$prefix.'/tmp'.' ... failed');
        }

        $ptmp = $prefix . '/tmp';
        $_temp = tempnam($prefix.'/tmp', 'gope');

        rm_rf($_temp);
        mkdir_p($_temp, 0700);
        $ok = @chdir($ptmp);

        if (!$ok) { // This should not happen, really ;)
            bail('chdir '.$ptmp.' ... failed');
        }

        print "ok\n";

        // Adjust TEMPDIR envvars
        if (!isset($_ENV)) {
            $_ENV = array();
        }
        $_ENV['TMPDIR'] = $_ENV['TEMP'] = $prefix.'/tmp';
    } else {
        $_temp = tempnam($_temp.'/tmp', 'gope');
    }
    $temp_dir = $ptmp = $_temp;
    return true;
}

// }}}
// {{{ my_env()
/*
(cox) In my system PHP 4.2.1 (both cgi & cli) $_ENV is empty
      but getenv() does work fine
*/
function my_env($var)
{
    if (is_array($_ENV) && isset($_ENV[$var])) {
        return $_ENV[$var];
    }
    return getenv($var);
}

// }}}
// {{{ detect_install_dirs()

function detect_install_dirs($_prefix = null) {
    global $temp_dir, $prefix, $bin_dir, $php_dir, $php_bin, $doc_dir, $data_dir, $test_dir;
    if (WINDOWS) {
        if ($_prefix === null) {
            $prefix = getcwd();
        } else {
            $prefix = $_prefix;
        }

        if (!@is_dir($prefix)) {
            if (@is_dir('c:\php5')) {
                $prefix = 'c:\php5';
            } elseif (@is_dir('c:\php4')) {
                $prefix = 'c:\php4';
            } elseif (@is_dir('c:\php')) {
                $prefix = 'c:\php';
            }
        }

        $bin_dir   = '$prefix';
        $php_dir   = '$prefix\pear';
        $doc_dir   = '$php_dir\docs';
        $data_dir  = '$php_dir\data';
        $test_dir  = '$php_dir\tests';
        $temp_dir   = '$prefix\temp';

        /*
         * Detects php.exe
         */
        if( $t=getenv('PHP_PEAR_PHP_BIN') ){
                $php_bin   = $t;
        } elseif ($t=getenv('PHP_BIN') ) {
            $php_bin   = $t;
        } elseif ( $t=which('php') ) {
            $php_bin = $t;
        } elseif ( is_file($prefix.'\cli\php.exe') ) {
            $php_bin = $prefix.'\cli\php.exe';
        } elseif ( is_file($prefix.'\php.exe') ) {
            $php_bin = $prefix.'\php.exe';
        }
        if( $php_bin && !is_file($php_bin) ){
            $php_bin = '';
        } else {
            if(!ereg(":",$php_bin)){
                $php_bin = getcwd().DIRECTORY_SEPARATOR.$php_bin;
            }
        }
        if (!is_file($php_bin)) {
            if (is_file('c:/php/cli/php.exe')) {
                $php_bin = 'c:/php/cli/php.exe';
            } elseif (is_file('c:/php5/php.exe')) {
                $php_bin = 'c:/php5/php.exe';
            } elseif (is_file('c:/php4/cli/php.exe')) {
                $php_bin = 'c:/php4/cli/php.exe';
            }
        }
    } else {
        if ($_prefix === null) {
            $prefix    = dirname(PHP_BINDIR);
        } else {
            $prefix = $_prefix;
        }
        $bin_dir   = '$prefix/bin';
        $php_dir   = '$prefix/share/pear';
        $doc_dir   = '$php_dir/docs';
        $data_dir  = '$php_dir/data';
        $test_dir  = '$php_dir/tests';
        $temp_dir   = '$prefix/temp';

        // check if the user has installed PHP with PHP or GNU layout
        if (@is_dir("$prefix/lib/php/.registry")) {
            $php_dir = '$prefix/lib/php';
        } elseif (@is_dir("$prefix/share/pear/lib/.registry")) {
            $php_dir = '$prefix/share/pear/lib';
            $doc_dir   = '$prefix/share/pear/docs';
            $data_dir  = '$prefix/share/pear/data';
            $test_dir  = '$prefix/share/pear/tests';
        } elseif (@is_dir("$prefix/share/php/.registry")) {
            $php_dir = '$prefix/share/php';
        }
    }
}

// }}}
// {{{ displayHTMLHeader

function displayHTMLHeader()
{
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
 <title>PEAR :: Installer :: Go-PEAR</title>
 <style type="text/css">
 <!--
    a {
        color:#000000;
        text-decoration: none;
    }
    a:visited {
        color:#000000;
        text-decoration: none;
    }
    a:active {
        color:#000000;
        text-decoration: none;
    }
    a:hover {
        color:#000000;
        text-decoration: underline;
    }

    a.green {
        color:#006600;
        text-decoration: none;
    }
    a.green:visited {
        color:#006600;
        text-decoration: none;
    }
    a.green:active {
        color:#006600;
        text-decoration: none;
    }
    a.green:hover {
        color:#006600;
        text-decoration: underline;
    }

    body, td, th {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 90%;
    }

    p {
        font-family: verdana,arial,helvetica,sans-serif;
    }

    th.pack {
        color: #FFFFFF;
        background: #009933;
        text-align: right;
    }

    td.package_info_title {
        color: #006600;
        font-weight: bold;
    }

    th.others {
        color: #006600;
        text-align: left;
    }

    em {
        font-weight: bold;
        font-style: italic;
    }

    .green {
        color: #006600;
    }
    .red {
        color: #006600;
    }

    span.headline {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 125%;
        font-weight: bold;
        color: #ffffff;
    }

    span.title {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 110%;
        font-weight: bold;
        color: #006600;
    }

    .newsDate {
        font-size: 85%;
        font-style: italic;
        color: #66cc66;
    }

    .compact {
        font-family: arial, helvetica, sans-serif;
        font-size: 90%;
    }

    .menuWhite {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 75%;
        color: #ffffff;
    }
    .menuBlack {
        font-family: verdana,arial,helvetica,sans-serif;
        text-decoration: none;
        font-weight: bold;
        font-size: 75%;
        color: #000000;
    }

    .sidebar {
        font-size: 85%;
    }

    code, pre, tt {
        font-family: Courier, "Courier New", monospace;
        font-size: 90%;
    }

    pre.php {
        border-color:       black;
        border-style:       dashed;
        border-width:       1px;
        background-color:   #eeeeee;
        padding:            5px;
    }

    h1 {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 140%;
        font-weight: bold;
        color: #006600;
    }

    h2 {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 125%;
        font-weight: bold;
        color: #006600;
    }

    h3 {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 110%;
        font-weight: bold;
        color: #006600;
    }

    small {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 75%;
    }

    a.small {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 75%;
        text-decoration: none;
    }

    .tableTitle {
        font-family: verdana,arial,helvetica,sans-serif;
        font-weight: bold;
    }

    .tableExtras {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 85%;
        color: #FFFFFF;
    }

    input {
        font-family: verdana,arial,helvetica,sans-serif;
    }

    textarea {
        font-family: verdana,arial,helvetica,sans-serif;
    }

    input.small, select.small {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 75%;
    }

    textarea.small {
        font-family: verdana,arial,helvetica,sans-serif;
        font-size: 75%;
    }

    form {
        margin-bottom : 0;
    }
 -->
 </style>
 <meta name="description" content="This is the Web Interface of the PEAR Installer" />
</head>

<body   topmargin="0" leftmargin="0"
        marginheight="0" marginwidth="0"
        bgcolor="#ffffff"
        text="#000000"
        link="#006600"
        alink="#cccc00"
        vlink="#003300"
>
<?php
}

// }}}
// {{{ displayHTML

function displayHTML($page = 'Welcome', $data = array())
{
    global $pfc_packages;

    displayHTMLHeader();

?>
<a name="TOP" /></a>
<table border="0" cellspacing="0" cellpadding="0" height="48" width="100%">
  <tr bgcolor="#339900">
    <td align="left" width="120">
      <img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=pearlogo" width="104" height="50" vspace="2" hspace="5" alt="PEAR">
    </td>
    <td align="left" valign="middle" width="20">
      &nbsp;
    </td>
    <td align="left" valign="middle">
      <span class="Headline">Go-PEAR</span>
    </td>
  </tr>

  <tr bgcolor="#003300"><td colspan="3"></td></tr>

  <tr bgcolor="#006600">
    <td align="right" valign="top" colspan="3">
        <span style="color: #ffffff">Version <?php echo GO_PEAR_VER; ?></span>&nbsp;<br />
    </td>
  </tr>

  <tr bgcolor="#003300"><td colspan="3"></td></tr>
</table>


<table cellpadding="0" cellspacing="0" width="100%">
 <tr valign="top">
  <td bgcolor="#f0f0f0" width="100">
   <table width="200" border="0" cellpadding="4" cellspacing="0">
    <tr valign="top">
     <td style="font-size: 90%" align="left" width="200">
       <br><br>
       <img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=smallpear" border="0">
       <a href="<?php echo basename(__FILE__); ?>?step=Welcome&restart=1" <?php if ($page == 'Welcome') echo ' class="green"'; ?>>
         Welcome to Go-PEAR
       </a><br/>

       <img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=smallpear" border="0">
       <a href="<?php echo basename(__FILE__); ?>?step=config" <?php if ($page == 'config') echo ' class="green"'; ?>>
         Configuration
       </a><br/>

       <img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=smallpear" border="0">
<?php if ($page == 'install') echo '<span class="green">'; ?>
         Complete installation<br/>
<?php if ($page == 'install') echo '</span>'; ?>

     </td>
    </tr>
   </table>
  </td>
  <td bgcolor="#cccccc" width="1" background="/gifs/checkerboard.gif"></td>
  <td>
   <table width="100%" cellpadding="10" cellspacing="0">
    <tr>
     <td valign="top">

<table border="0">
<tr>
  <td width="20">
  </td>
  <td>
<?php
    if ($page == 'error') {
?>
            <span class="title">Error</span><br/>
            <br/>
<?php
        $value = $data;
        if (preg_match('/ok$/', $value)) {
            $value = preg_replace('/(ok)$/', '<span class="green">\1</span>', $value);
        }
        if (preg_match('/failed$/', $value)) {
            $value = preg_replace('/(failed)$/', '<span style="color: #ff0000">\1</span>', $value);
        }
        if (preg_match('/^install ok:/', $value)) {
            $value = preg_replace('/^(install ok:)/', '<span class="green">\1</span>', $value);
        }
        if (preg_match('/^Warning:/', $value)) {
            $value = '<span style="color: #ff0000">'.$value.'</span>';
        }

        echo nl2br($value);
    } elseif ($page == 'Welcome') {
?>
            <span class="title">Welcome to go-pear <?php echo GO_PEAR_VER; ?>!</span><br/>
            <br/>
            Go-pear will install the Web Frontend of the PEAR Installer and all the needed <br/>
            files. This frontend is your tool for PEAR installation and maintenance.<br/>
            <br/>
            Go-pear also lets you download and install the PEAR packages bundled<br/>
            with PHP: <?php echo implode(', ', $GLOBALS['pfc_packages']); ?>.<br/>
            <br/>
            <a href="<?php echo basename(__FILE__); ?>?step=config" class="green">Next &gt;&gt;</a>
<?php
    } elseif ($page == 'config') {
        if (!empty($GLOBALS['http_proxy'])) {
            list($proxy_host, $proxy_port) = explode(':', $GLOBALS['http_proxy']);
        } else {
            $proxy_host = $proxy_port = '';
        }
?>
            <form action="<?php echo basename(__FILE__);?>?step=install" method="post">
            <span class="title">Configuration</span><br/>
            <br/>
            HTTP proxy (host:port):
            <input type="text" name="proxy[host]" value="<?php echo $proxy_host;?>">
            <input type="text" name="proxy[port]" value="<?php echo $proxy_port;?>" size="6">
            <br/><br/><hr/><br/>
            Below is a suggested file layout for your new PEAR installation. <br/>
            <br/>
            <table border="0">
              <TR>
                <TD valign="top"><img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=note" border="0"></TD>
                <TD>
                  <span class="green">
                    <b>Note:</b> Make sure that PHP has the permission to access the specified<br/>
                    directories.<br/><br/>
                  </span>
                </TD>
              </TR>
            </table>
            <TABLE border="0">
<?php
    // Display error messages
        if (isset($GLOBALS['www_errors']) && sizeof($GLOBALS['www_errors']) ) {
            $www_errors = $GLOBALS['www_errors'];
            echo "<tr><td>";
            echo '<span class="red">ERROR(S):</span>';
            echo "</td></tr>";
            foreach ($www_errors as $n => $var) {
                echo "<tr><td>";
                echo '<span class="red">'.$GLOBALS['config_desc'][$n].': </span>';
                echo "</td><td>";
                echo '<span class="red">'.$www_errors[$n].'</span>';
                echo "<br>\n";
                echo "</td></tr>\n";
            }
        }

        foreach ($GLOBALS['config_vars'] as $n => $var) {
            printf('<tr><td>%d. %s</td><td><input type="text" name="config[%s]" value="%s"></td></tr>',
            $n,
            $GLOBALS['config_desc'][$var],
            $var,
            $GLOBALS[$var]);
        }
?>
            </TABLE>
            <br/><hr/><br/>
            The following PEAR packages are common ones, and can be installed<br/>
            by go-pear too: <br/>
<?php echo implode(', ', $GLOBALS['pfc_packages']);?>.<br/>
            <input type="checkbox" name="install_pfc" <?php if($GLOBALS['install_pfc']) ?>> Install those too<br/>
            <br/><br/>
            <table border="0">
              <TR>
                <TD valign="top"><img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=note" border="0"></TD>
                <TD>
                  <span class="green">
                      <b>Note:</b> Installation might take some time, because go-pear has to download<br/>
                      all needed files from pear.php.net. Just be patient and wait for the next<br/>
                      page to load.<br/>
                  </span>
                </TD>
              </TR>
            </table>
            <br>
            <input type="checkbox" name="BCmode" id="BCmode" checked> Compatibility-Mode for old non-DOM Browsers<br/>
            <script type="text/javascript">
            <!--
                if (document.getElementById('BCmode')) {
                    document.getElementById('BCmode').checked = 0;
                };
            // -->
            </script>

<?php
        if (WINDOWS && phpversion() == '4.1.1') {
?>
                    <table border="0">
                      <TR>
                        <TD valign="top"><img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=note" border="0"></TD>
                        <TD>
                          <span style="color: #ff0000">
                              <b>Warning:</b> Your PHP version (4.1.1) might be imcompatible with go-pear due to a bug<br/>
                              in your PHP binary. If the installation crashes you might want to update your PHP version.</br>
                          </span>
                        </TD>
                      </TR>
                    </table>
<?php
        }
?>
            <br/>
            <input type="submit" value="Install" onClick="javascript: submitButton.value='Downloading and installing ... please wait ...'" name="submitButton">
            </form>
<?php
    } elseif ($page == 'install') {
?>
            <span class="title">Installation Complete - Summary</span><br/>
<?php
        displayHTMLInstallationSummary($data);
    } elseif ($page == 'preinstall') {
?>
            <span class="title">Installation in progress ...</span><br/>
            <br/>
            <script language="javascript">
            <!--

                var progress;
                var downloadprogress;
                progress = 0;
                downloadprogress = 0;

                function setprogress(value)
                {
                    progress = value;

                    prog = document.getElementById('installation_progress');
                    prog.innerHTML = progress + " %";
                    progress2 = progress / 10;
                    progress2 = Math.floor(progress2);
                    for (i=0; i < 10; i++)
                        document.getElementById('progress_cell_'+i).style.backgroundColor = "#cccccc";
                    switch(progress2)
                    {
                        case 10:
                            document.getElementById('progress_cell_9').style.backgroundColor = "#006600";
                        case  9:
                            document.getElementById('progress_cell_8').style.backgroundColor = "#006600";
                        case  8:
                            document.getElementById('progress_cell_7').style.backgroundColor = "#006600";
                        case  7:
                            document.getElementById('progress_cell_6').style.backgroundColor = "#006600";
                        case  6:
                            document.getElementById('progress_cell_5').style.backgroundColor = "#006600";
                        case  5:
                            document.getElementById('progress_cell_4').style.backgroundColor = "#006600";
                        case  4:
                            document.getElementById('progress_cell_3').style.backgroundColor = "#006600";
                        case  3:
                            document.getElementById('progress_cell_2').style.backgroundColor = "#006600";
                        case  2:
                            document.getElementById('progress_cell_1').style.backgroundColor = "#006600";
                        case  1:
                            document.getElementById('progress_cell_0').style.backgroundColor = "#006600";
                    };
                }

                function addprogress(value)
                {
                    progress += value;
                    setprogress(progress);
                }

                function setdownloadfile(value)
                {
                    setdownloadprogress(0);

                    prog = document.getElementById('download_file');
                    prog.innerHTML = 'Downloading '+value+' ...';
                };

                function setdownloadprogress(value)
                {
                    downloadprogress = value;

                    prog = document.getElementById('download_progress');
                    prog.innerHTML = downloadprogress + " %";
                    progress2 = downloadprogress / 10;
                    progress2 = Math.floor(progress2);
                    for (i=0; i < 10; i++)
                        document.getElementById('download_progress_cell_'+i).style.backgroundColor = "#cccccc";
                    switch(progress2)
                    {
                        case 10:
                            document.getElementById('download_progress_cell_9').style.backgroundColor = "#006600";
                        case  9:
                            document.getElementById('download_progress_cell_8').style.backgroundColor = "#006600";
                        case  8:
                            document.getElementById('download_progress_cell_7').style.backgroundColor = "#006600";
                        case  7:
                            document.getElementById('download_progress_cell_6').style.backgroundColor = "#006600";
                        case  6:
                            document.getElementById('download_progress_cell_5').style.backgroundColor = "#006600";
                        case  5:
                            document.getElementById('download_progress_cell_4').style.backgroundColor = "#006600";
                        case  4:
                            document.getElementById('download_progress_cell_3').style.backgroundColor = "#006600";
                        case  3:
                            document.getElementById('download_progress_cell_2').style.backgroundColor = "#006600";
                        case  2:
                            document.getElementById('download_progress_cell_1').style.backgroundColor = "#006600";
                        case  1:
                            document.getElementById('download_progress_cell_0').style.backgroundColor = "#006600";
                    };
                };

            // -->
            </script>
            <table style="border-width: 1px; border-color: #000000" cellspacing="0" cellpadding="0">
            <tr>
              <td>
                <table border="0">
                  <tr>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_0">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_1">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_2">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_3">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_4">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_5">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_6">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_7">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_8">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="progress_cell_9">&nbsp;</td>
                    <td bgcolor="#ffffff" width="10" height="20">&nbsp;</td>
                    <td bgcolor="#ffffff" height="20" id="installation_progress" class="green">0 %</td>
                  </tr>
                </table>
                <br>
                <table border="0">
                  <tr>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_0">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_1">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_2">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_3">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_4">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_5">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_6">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_7">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_8">&nbsp;</td>
                    <td bgcolor="#cccccc" width="10" height="20" id="download_progress_cell_9">&nbsp;</td>
                    <td bgcolor="#ffffff" width="10" height="20">&nbsp;</td>
                    <td bgcolor="#ffffff" height="20" id="download_progress" class="green">0 %</td>
                    <td bgcolor="#ffffff" width="10" height="20">&nbsp;</td>
                    <td bgcolor="#ffffff" height="20" id="download_file" class="green"></td>
                  </tr>
                </table>
                <br>
                <iframe src="<?php echo basename(__FILE__); ?>?step=install-progress&amp;<?php echo SID;?>" width="700" height="700" frameborder="0" marginheight="0" marginwidth="0"></iframe>
              </td>
            </tr>
            </table>
<?php
    }
?>
  </td>
</tr>
</table>


</td>
    </tr>
   </table>
  </td>

 </tr>
</table>
<?php
    displayHTMLFooter();
}

// }}}
// {{{ displayHTMLFooter

function displayHTMLFooter()
{
    ?>
    </body>
    </html>
    <?php
};

// }}}
// {{{ displayHTMLInstallationSummary

function displayHTMLInstallationSummary($data = '')
{
    $next     = NULL;
    $file   = $GLOBALS['webfrontend_file'];
    $doc_root = strip_magic_quotes($_SERVER['DOCUMENT_ROOT']);
    $file_dir = dirname(__FILE__);
    if ( WINDOWS ) {
        $file   = str_replace('/', '\\', strtolower($file));
        $doc_root = str_replace('/', '\\', strtolower($doc_root));
        $file_dir = str_replace('/', '\\', strtolower($file_dir));
    }

    if ($doc_root && substr($file, 0, strlen($doc_root)) == $doc_root) {
        $next = substr($file, strlen($doc_root));
    } elseif ($file_dir && substr($file, 0, strlen($file_dir)) == $file_dir) {
        $next = substr($file, strlen($file_dir));
    }

    if ($data) {
        echo "<br/>".$data;
    }
?>
            <br/>
            <table border="0">
              <TR>
                <TD valign="top"><img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=note" border="0"></TD>
                <TD>
                  <span class="green">
                  <b>Note:</b> To use PEAR without any problems you need to add your<br/>
                  PEAR Installation path (<?php echo $GLOBALS['php_dir']; ?>)<br>
                  to your <a href="http://www.php.net/manual/en/configuration.directives.php#ini.include_path">include_path</a>.<br/>
                      <br/>
                  Using a .htaccess file or directly edit httpd.conf would be working solutions<br/>
                  for Apache running servers, too.<br/>
                  </span>
                </TD>
              </TR>
            </table>
            <br/>
            For more information about PEAR, see:<br/>
            <a href="http://pear.php.net/faq.php" target="_new" class="green">PEAR FAQ</a><br/>
            <a href="http://pear.php.net/manual/" target="_new" class="green">PEAR Manual</a><br/>
            <br/>
            Thanks for using go-pear!<br/>
            <br/>
<?php
    if ($next === NULL) {
?>
                    <table border="0">
                      <TR>
                        <TD valign="top"><img src="<?php echo basename(__FILE__); ?>?action=img&amp;img=note" border="0"></TD>
                        <TD>
                          <span style="color: #ff0000">
                            <b>Warning:</b> Go-PEAR was not able to determine the URL to the newly<br/>
                            installed Web Frontend of the PEAR Installer. Please access it manually.<br/>
                            Since you specified the prefix, you should know how to do so.<br/>
                          </span>
                        </TD>
                      </TR>
                    </table>
<?php
    } else {
        if ($_GET['step'] == 'install-progress') {
?>
                        <a href="<?php echo $next;?>" class="green" target="_parent">Start Web Frontend of the PEAR Installer &gt;&gt;</a>
<?php
        } else {
?>
                        <a href="<?php echo $next;?>" class="green">Start Web Frontend of the PEAR Installer &gt;&gt;</a>
<?php
        }
    }
}

// }}}
// {{{ strip_magic_quotes

function strip_magic_quotes($value)
{
    if (ini_get('magic_quotes_gpc')) {
        return stripslashes($value);
    }
    return $value;
};

// }}}
// {{{ showImage

function showImage($img)
{
    $images = array(
        'smallpear' => array(
            'type' => 'gif',
            'data' => 'R0lGODlhEQATAMQAAAAAACqUACiTAC2WAC+YAzKZBTSaBsHgszOZADCYADmcB4TCZp3Ohtfrzd/v1+by4PD47DaaAz+fDUijF2WyOlCoHvT58VqtJPn893y+S/v9+f7//f3+/Pz9+////////ywAAAAAEQATAAAFkqAnjiR5NGXqcdpCoapnMVRdWbEHUROVVROYalHJTCaVAKWTcjAUGckgQY04SJAFMhJJIL5e4a5I6X6/gwlkRIwOzucAY9SYZBRvOCKheIwYFxR5enxCLhVeemAHbBQVg4SMIoCCinsKVyIOdlKKAhQcJFpGiWgFQiIYPxeJCQEEcykcDIgDAwYUkjEWB70NGykhADs=',
            ),
        'pearlogo' => array(
            'type' => 'gif',
            'data' => 'R0lGODlhaAAyAMT/AMDAwP3+/TWaAvD47Pj89vz++zebBDmcBj6fDEekFluvKmu3PvX68ujz4XvBS8LgrNXqxeHw1ZnPaa/dgvv9+cLqj8LmltD2msnuls3xmszwmf7+/f///wAAAAAAAAAAACH5BAEAAAAALAAAAABoADIAQAX/ICCOZGmeaKqubOtWWjwJphLLgH1XUu//C1Jisfj9YLEKQnSY3GaixWQqQTkYHM4AMulNLJFC9pEwIW/odKU8cqTfsWoTTtcomU4ZjbR4ZP+AgYKCG0EiZ1AuiossEhwEXRMEg5SVWQ6MmZqKWD0QlqCUEHubpaYlExwRPRZioZZVp7KzKQoSDxANDLsNXA5simd2FcQYb4YAc2jEU80TmAAIztPCMcjKdg4OEsZJmwIWWQPQI4ikIwtoVQnddgrv8PFlCWgYCwkI+fp5dkvJ/IlUKMCy6tYrDhNIIKLFEAWCTxse+ABD4SClWA0zovAjcUJFi6EwahxZwoGqHhFA/4IqoICkyxQSKkbo0gDkuBXV4FRAJkRCnTgi2P28IcEfk5xpWppykFJVuScmEvDTEETAVJ6bEpypcADPkz3pvKVAICHChkC7siQ08zVqu4Q6hgIFEFZuEn/KMgRUkaBmAQs+cEHgIiHVH5EAFpIgW4+NT6LnaqhDwe/Ov7YOmWZp4MkiAWBIl0kAVsJWuzcYpdiNgddc0E8cKBAu/FElBwagMb88ZZKDRAkWJtkWhHh3wwUbKHQJN3wQAaXGR2LpArv5oFHRR34C7Mf6oLXZNfqBgNI7oOLhj1f8PaGpygHQ0xtP8MDVKwYTSKcgxr9/hS6/pCCAAg5M4B9/sWh1YP9/XSgQWRML/idBfKUc4IBET9lFjggKhDYZAELZJYEBI2BDB3ouNBEABwE8gAwiCcSYgAKqPdEVAG7scM8BPPZ4AIlM+OgjAgpMhRE24OVoBwsIFEGFA7ZkQQBWienWxmRa7XDjKZXhBdAeSmKQwgLuUVLICa6VEKIGcK2mQWoVZHCBXJblJUFkY06yAXlGsPIHBEYdYiWHb+WQBgaIJqqoHFNpgMGB7dT5ZQuG/WbBAIAUEEFNfwxAWpokTIXJAWdgoJ9kRFG2g5eDRpXSBpEIF0oEQFaZhDbaSFANRgqcJoEDRARLREtxOQpsPO906ZUeJgjQB6dZUPBAdwcF8KLXXRVQaKFcsRRLJ6vMiiCNKxRE8ECZKgUA3Va4arOAAqdGRWO7uMZH5AL05gvsjQbg6y4NCjQ1kw8TVGcbdoKGKx8j3bGH7nARBArqwi0gkFJBrZiXBQRbHoIgnhSjcEBKfD7c3HMhz+JIQSY3t8GGKW+SUhfUajxGzKd0IoHBNkNQK86ZYEqdzYA8AHQpqXRUm80oHs1CAgMoBxzRqvzs9CIKECC1JBp7enUpfXHApwVYNAfo16c4IrYPLVdSAJVob7IAtCBFQGHcs/RRdiUDPHA33oADEAIAOw==',
            ),
        'note' => array(
            'type' => 'png',
            'data' => 'iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAAAAADFHGIkAAAAAmJLR0QAAKqNIzIAAAEESURBVHjaZZIhksMwDEV9voWFSwsLA0MLDf8VdARBUUNBQ1FBHcErZ5M0baXJjOPnb0vfLuMMn3H+lWMgBKL89A1Eq9Q9IrwB+gIOsnMPBR8giMclguQfBGS8x5xIoPQxnxqb4LL/eQ4l2AVNONP2ZshLCqJ3qqzWtT5pNgNnLU4OcNbuiqaLmFmHGhJ0TCMC99+f2wphlhaOYjuQVc0IIzLH2BRWfQoWsNSjct8AVop4rF3belTuVAb3MRj6kLrcTwtIy+g03V1vC57t1XrMzqfP5pln5yLTkk7+5UhstvOni1X3ixLEdf2c36+W0Q7kOb48hnSRLI/XdNPfX4kpMkgP5R+elfdkDPprQgAAAEN0RVh0U29mdHdhcmUAQCgjKUltYWdlTWFnaWNrIDQuMi44IDk5LzA4LzAxIGNyaXN0eUBteXN0aWMuZXMuZHVwb250LmNvbZG6IbgAAAAqdEVYdFNpZ25hdHVyZQAzYmQ3NDdjNWU0NTgwNzAwNmIwOTBkZDNlN2EyNmM0NBTTk/oAAAAOdEVYdFBhZ2UAMjR4MjQrMCswclsJMQAAAABJRU5ErkJggg==',
            ),
        );

    Header('Content-Type: image/'.$images[$img]['type']);
    echo base64_decode($images[$img]['data']);
};

// }}}
// {{{ displayHTMLProgress

function displayHTMLProgress($progress)
{
    if (!(WEBINSTALLER && isset($_SESSION['go-pear']['DHTML']) && $_SESSION['go-pear']['DHTML'])) {
        return;
    };
    $msg = ob_get_contents();
    ob_end_clean();

    $msg = explode("\n", $msg);
    foreach($msg as $key => $value) {
        if (preg_match('/ok$/', $value)) {
            $value = preg_replace('/(ok)$/', '<span class="green">\1</span>', $value);
        };
        if (preg_match('/failed$/', $value)) {
            $value = preg_replace('/(failed)$/', '<span style="color: #ff0000">\1</span>', $value);
        };
        if (preg_match('/^install ok:/', $value)) {
            $value = preg_replace('/^(install ok:)/', '<span class="green">\1</span>', $value);
        };
        if (preg_match('/^Warning:/', $value)) {
            $value = '<span style="color: #ff0000">'.$value.'</span>';
        };
        $msg[$key] = $value;
    };
    $msg = implode('<br>', $msg);

    $msg.='<script type="text/javascript"> parent.setprogress('.((int) $progress).');  </script>';

    echo $msg;
    ob_start();
};

// }}}
// {{{ displayHTMLDownloadProgress

function displayHTMLDownloadProgress($progress)
{
    if (!(WEBINSTALLER && isset($_SESSION['go-pear']['DHTML']) && $_SESSION['go-pear']['DHTML'])) {
        return;
    };
    $msg = ob_get_contents();
    ob_end_clean();

    echo '<script type="text/javascript"> parent.setdownloadprogress('.((int) $progress).');  </script>';

    ob_start();
    echo $msg;
};

// }}}
// {{{ displayHTMLSetDownload

function displayHTMLSetDownload($file)
{
    if (!(WEBINSTALLER && isset($_SESSION['go-pear']['DHTML']) && $_SESSION['go-pear']['DHTML'])) {
        return;
    };
    $msg = ob_get_contents();
    ob_end_clean();

    echo '<script type="text/javascript"> parent.setdownloadfile("'.$file.'");  </script>';

    ob_start();
    echo $msg;
};

// }}}
// {{{ win32BrowseForFolder

/*
 * Create a vbs script to browse the getfolder dialog, called
 * by cscript, if it's available.
 * $label is the label text in the header of the dialog box
 *
 * TODO:
 * - Do not show Control panel
 * - Replace WSH with calls to w32 as soon as callbacks work
 * @Author Pierrre-Alain Joye
 */
function win32BrowseForFolder($label)
{
    global $ptmp;
    static $wshSaved=false;
    static $cscript='';
$wsh_browserfolder = 'Option Explicit
Dim ArgObj, var1, var2, sa, sFld
Set ArgObj = WScript.Arguments
Const BIF_EDITBOX = &H10
Const BIF_NEWDIALOGSTYLE = &H40
Const BIF_RETURNONLYFSDIRS   = &H0001
Const BIF_DONTGOBELOWDOMAIN  = &H0002
Const BIF_STATUSTEXT         = &H0004
Const BIF_RETURNFSANCESTORS  = &H0008
Const BIF_VALIDATE           = &H0020
Const BIF_BROWSEFORCOMPUTER  = &H1000
Const BIF_BROWSEFORPRINTER   = &H2000
Const BIF_BROWSEINCLUDEFILES = &H4000
Const OFN_LONGNAMES = &H200000
Const OFN_NOLONGNAMES = &H40000
Const ssfDRIVES = &H11
Const ssfNETWORK = &H12
Set sa = CreateObject("Shell.Application")
var1=ArgObj(0)
Set sFld = sa.BrowseForFolder(0, var1, BIF_EDITBOX + BIF_VALIDATE + BIF_BROWSEINCLUDEFILES + BIF_RETURNFSANCESTORS+BIF_NEWDIALOGSTYLE , ssfDRIVES )
if not sFld is nothing Then
    if not left(sFld.items.item.path,1)=":" Then
        WScript.Echo sFld.items.item.path
    Else
        WScript.Echo "invalid"
    End If
Else
    WScript.Echo "cancel"
End If
';
    if( !$wshSaved){
        $cscript = $ptmp.DIRECTORY_SEPARATOR."bf.vbs";
        $fh = fopen($cscript,"wb+");
        fwrite($fh,$wsh_browserfolder,strlen($wsh_browserfolder));
        fclose($fh);
        $wshSaved  = true;
    }
    exec('cscript '.$cscript.' "'.$label.'" //noLogo',$arPath);
    if($arPath[0]=='' || $arPath[0]=='cancel'){
        return '';
    } elseif ($arPath[0]=='invalid') {
        echo "Invalid Path.\n";
        return '';
    }
    return $arPath[0];
}

// }}}
// {{{ win32CreateRegEnv

/*
 * Generates a registry addOn for Win32 platform
 * This addon set PEAR environment variables
 * @Author Pierrre-Alain Joye
 */
function win32CreateRegEnv()
{
    global $prefix, $bin_dir, $php_dir, $php_bin, $doc_dir, $data_dir, $test_dir, $temp_dir;
    $nl = "\r\n";
    $reg ='REGEDIT4'.$nl.
            '[HKEY_CURRENT_USER\Environment]'.$nl.
            '"PHP_PEAR_SYSCONF_DIR"="'.addslashes($prefix).'"'.$nl.
            '"PHP_PEAR_INSTALL_DIR"="'.addslashes($php_dir).'"'.$nl.
            '"PHP_PEAR_DOC_DIR"="'.addslashes($doc_dir).'"'.$nl.
            '"PHP_PEAR_BIN_DIR"="'.addslashes($bin_dir).'"'.$nl.
            '"PHP_PEAR_DATA_DIR"="'.addslashes($data_dir).'"'.$nl.
            '"PHP_PEAR_PHP_BIN"="'.addslashes($php_bin).'"'.$nl.
            '"PHP_PEAR_TEST_DIR"="'.addslashes($test_dir).'"'.$nl;

    $fh = fopen($prefix.DIRECTORY_SEPARATOR.'PEAR_ENV.reg','wb');
    if($fh){
        fwrite($fh, $reg ,strlen($reg));
        fclose($fh);
        echo "

* WINDOWS ENVIRONMENT VARIABLES *
For convenience, a REG file is available under $prefix\\PEAR_ENV.reg .
This file creates ENV variables for the current user.

Double-click this file to add it to the current user registry.

";
    }
}

// }}}
// {{{ win32DetectPHPSAPI

/*
 * Try to detect the kind of SAPI used by the
 * the given php.exe.
 * @Author Pierrre-Alain Joye
 */
function win32DetectPHPSAPI()
{
    global $php_bin,$php_sapi_name;
    if (WEBINSTALLER) {
        return $php_sapi_name;
    }
    if($php_bin!=''){
        exec($php_bin.' -v', $res);
        if(is_array($res)) {
            if( isset($res[0]) && strpos($res[0],"(cli)")) {
                return 'cli';
            }
            if( isset($res[0]) && strpos($res[0],"cgi")) {
                return 'cgi';
            } else {
                return 'unknown';
            }
        }
    }
    return 'unknown';
}

// }}}
// {{{ getPhpiniPath

/*
 * Get the php.ini file used with the current
 * process or with the given php.exe
 *
 * Horrible hack, but well ;)
 *
 * Not used yet, will add the support later
 * @Author Pierre-Alain Joye <paj@pearfr.org>
 */
function getPhpiniPath()
{
    $pathIni = get_cfg_var('cfg_file_path');
    if( $pathIni && is_file($pathIni) ){
        return $pathIni;
    }

    // Oh well, we can keep this too :)
    // I dunno if get_cfg_var() is safe on every OS
    if (WINDOWS) {
        // on Windows, we can be pretty sure that there is a php.ini
        // file somewhere
        do {
            $php_ini = PHP_CONFIG_FILE_PATH . DIRECTORY_SEPARATOR . 'php.ini';
            if ( @file_exists($php_ini) ) break;
            $php_ini = 'c:\winnt\php.ini';
            if ( @file_exists($php_ini) ) break;
            $php_ini = 'c:\windows\php.ini';
        } while (false);
    } else {
        $php_ini = PHP_CONFIG_FILE_PATH . DIRECTORY_SEPARATOR . 'php.ini';
    }

    if( @is_file($php_ini) ){
        return $php_ini;
    }

    // We re running in hackz&troubles :)
    ob_implicit_flush(false);
    ob_start();
    phpinfo(INFO_GENERAL);
    $strInfo = ob_get_contents ();
    ob_end_clean();
    ob_implicit_flush(true);

    if ( php_sapi_name() != 'cli' ) {
        $strInfo = strip_tags($strInfo,'<td>');
        $arrayInfo  = explode("</td>", $strInfo );
        $cli = false;
    } else {
        $arrayInfo = explode("\n",$strInfo);
        $cli = true;
    }

    foreach($arrayInfo as $val){
        if ( strpos($val,"php.ini") ) {
            if($cli){
                list(,$pathIni) = explode('=>',$val);
            } else {
                $pathIni = strip_tags(trim($val) );
            }
            $pathIni = trim($pathIni);
            if(is_file($pathIni)){
                return $pathIni;
            }
        }
    }

    return false;
}

// }}}
// {{{ alterPhpIni

/*
 * Not optimized, but seems to work, if some nice
 * peardev will test it? :)
 *
 * @Author Pierre-Alain Joye <paj@pearfr.org>
 */
function alterPhpIni($pathIni='')
{
    global $php_dir, $prefix;

    $iniSep = WINDOWS?';':':';

    if( $pathIni=='' ){
        $pathIni =  getphpinipath();
    }

    $arrayIni = file($pathIni);
    $i=0;
    $found=0;

    // Looks for each active include_path directives
    foreach ( $arrayIni as $iniLine ) {
        $iniLine = trim($iniLine);
        $iniLine = str_replace(array("\n","\r"),array(),$iniLine);
        if( preg_match("/^include_path/",$iniLine) ){
            $foundAt[] = $i;
            $found++;
        }
        $i++;
    }

    if ( $found ) {
        $includeLine = $arrayIni[$foundAt[0]];
        list(,$currentPath)=explode('=',$includeLine);

        $currentPath = trim($currentPath);
        if(substr($currentPath,0,1)=='"'){
            $currentPath = substr($currentPath,1,strlen($currentPath)-2);
        }

        $arrayPath = explode($iniSep, $currentPath);
        if( $arrayPath[0]=='.' ){
            $newPath[0] = '.';
            $newPath[1] = $php_dir;
            array_shift($arrayPath);
        } else {
            $newPath[0] = $php_dir;
        }

        foreach( $arrayPath as $path ){
            $newPath[]= $path;
        }
    } else {
        $newPath[0] = '.';
        $newPath[1] = $php_dir;

    }
    $nl = WINDOWS?"\r\n":"\n";
    $includepath = 'include_path="'.implode($iniSep,$newPath).'"';
    $newInclude =   "$nl$nl;***** Added by go-pear$nl".
                    $includepath.
                    $nl.";*****".
                    $nl.$nl;

    $arrayIni[$foundAt[0]] =  $newInclude;

    for( $i=1; $i<$found; $i++){
        $arrayIni[$foundAt[$i]]=';'.trim($arrayIni[$foundAt[$i]]);
    }

    $newIni = implode("",$arrayIni);
    if ( !($fh = @fopen($pathIni, "wb+")) ){
        $prefixIni = $prefix.DIRECTORY_SEPARATOR."php.ini-gopear";
        $fh = fopen($prefixIni, "wb+");
        if ( !$fh ) {
            echo
"
******************************************************************************
WARNING!  I cannot write to $pathIni nor in $prefix/php.ini-gopear. Please
modify manually your php.ini by adding:

$includepath

";
            return false;
        } else {
            fwrite($fh, $newIni, strlen($newIni));
            fclose($fh);
            echo
"
******************************************************************************
WARNING!  I cannot write to $pathIni, but I succesfully created a php.ini
under <$prefix/php.ini-gopear>. Please replace the file <$pathIni> with
<$prefixIni> or modify your php.ini by adding:

$includepath

";

        }
    } else {
        fwrite($fh, $newIni, strlen($newIni));
        fclose($fh);
        echo "
php.ini <$pathIni> include_path updated.
";
    }
    return true;
}
