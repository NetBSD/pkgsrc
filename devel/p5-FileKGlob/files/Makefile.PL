# $NetBSD: Makefile.PL,v 1.1.1.1 1999/05/12 20:47:13 bad Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'File::KGlob',
    'DISTNAME'  => 'FileKGlob',
    'VERSION'   => '1.2',
    'linkext'   => { LINKTYPE=>'' },	# no link needed
    'dist'      => {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
