# $NetBSD: Makefile.PL,v 1.1 2000/08/27 07:11:15 jlam Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'Array::PrintCols',
    'DISTNAME'  => 'Array-PrintCols',
    'VERSION'   => '1.2',
    'linkext'   => { LINKTYPE=>'' },	# no link needed
    'dist'      => {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
