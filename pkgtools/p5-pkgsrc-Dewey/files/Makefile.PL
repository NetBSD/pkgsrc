use 5.008007;
use ExtUtils::MakeMaker;
WriteMakefile(
    NAME              => 'pkgsrc::Dewey',
    VERSION_FROM      => 'Dewey.pm', # finds $VERSION
    INC               => '-I.',
    OBJECT            => '$(O_FILES)', # link all the C files too
);
