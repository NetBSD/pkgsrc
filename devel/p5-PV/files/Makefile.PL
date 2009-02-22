# $NetBSD: Makefile.PL,v 1.3 2009/02/22 18:08:02 wiz Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'PV',
    'DISTNAME'  => 'PV.pm',
    'VERSION'   => '1.5',
    'linkext'   => { LINKTYPE=>'' },	# no link needed
    'dist'      => {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
