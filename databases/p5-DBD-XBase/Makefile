# $NetBSD: Makefile,v 1.1.1.1 2003/06/03 22:27:12 salo Exp $
#

DISTNAME=	DBD-XBase-0.232
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xbs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://www.fi.muni.cz/~adelton/perl/
COMMENT=	perl DBI/DBD driver for XBase (dBase/FoxPro) databases

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XBase/.packlist

.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
