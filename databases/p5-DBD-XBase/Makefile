# $NetBSD: Makefile,v 1.4 2004/01/01 15:37:54 salo Exp $
#

DISTNAME=	DBD-XBase-0.241
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xbs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.fi.muni.cz/~adelton/perl/
COMMENT=	Perl DBI/DBD driver for XBase (dBase/FoxPro) databases

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XBase/.packlist

.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
