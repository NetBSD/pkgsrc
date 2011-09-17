# $NetBSD: cpan-DB_File-hints-netbsd.pl,v 1.1 2011/09/17 18:51:36 brook Exp $

# cpan/DB_File:
# NetBSD does not provide -ldb, so avoid linking to it

$self->{LIBS} = [''];
