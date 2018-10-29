# $NetBSD: cpan-DB_File-hints-minix.pl,v 1.1 2018/10/29 14:25:25 sevan Exp $

# cpan/DB_File:
# Minix through NetBSD does not provide -ldb, so avoid linking to it

$self->{LIBS} = [''];
