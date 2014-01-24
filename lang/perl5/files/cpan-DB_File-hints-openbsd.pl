# $NetBSD: cpan-DB_File-hints-openbsd.pl,v 1.1 2014/01/24 16:37:19 ryoon Exp $

# cpan/DB_File:
# OpenBSD does not provide -ldb, so avoid linking to it

$self->{LIBS} = [''];
