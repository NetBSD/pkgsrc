# $NetBSD: Makefile,v 1.3 2003/07/17 21:28:31 grant Exp $
#

VER=		0.25
DISTNAME=	DBD-SQLite-${VER}
PKGNAME=	p5-${DISTNAME}
# PKGREVISION=	3
SVR4_PKGNAME=	p5dsl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSERGEANT/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	perl DBI/DBD driver for sqlite databases

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/SQLite/.packlist

.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
