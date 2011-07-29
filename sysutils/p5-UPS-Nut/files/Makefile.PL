use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    NAME         => 'UPS::Nut',
    VERSION_FROM => 'Nut.pm', # finds $VERSION
    AUTHOR       => 'Gabor Kiss <kissg@ssg.ki.iif.hu>',
    ABSTRACT     => 'A module for communicating with a UPS via the NUT upsd'
);
