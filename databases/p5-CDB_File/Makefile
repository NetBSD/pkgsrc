# $NetBSD: Makefile,v 1.1.1.1 2008/06/03 10:58:23 ghen Exp $

DISTNAME=		CDB_File-0.96
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CDB_File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module to use CDB files

PERL5_PACKLIST=		auto/CDB_File/.packlist

REPLACE_PERL+=		bun-x.pl

.include "../../mk/bsd.prefs.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
