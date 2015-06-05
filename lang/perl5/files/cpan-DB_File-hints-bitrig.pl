# $NetBSD: cpan-DB_File-hints-bitrig.pl,v 1.1 2015/06/05 12:25:30 sevan Exp $

# cpan/DB_File:
# Bitrig does not provide -ldb, so avoid linking to it

$self->{LIBS} = [''];
