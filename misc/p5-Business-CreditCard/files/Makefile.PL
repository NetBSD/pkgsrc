# $NetBSD: Makefile.PL,v 1.1 2000/08/27 07:11:15 jlam Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'Business::CreditCard',
    'DISTNAME'  => 'CreditCard.pm',
    'VERSION'   => '0.1',
    'linkext'   => { LINKTYPE=>'' },	# no link needed
    'dist'      => {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
