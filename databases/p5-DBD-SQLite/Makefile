# $NetBSD: Makefile,v 1.7 2005/01/04 15:28:38 wiz Exp $
#

VER=		0.25
DISTNAME=	DBD-SQLite-${VER}
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5dsl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSERGEANT/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl DBI/DBD driver for sqlite databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/SQLite/.packlist

CFLAGS+=	-DUINT32_TYPE=uint32_t -DUINT16_TYPE=uint16_t
CFLAGS+=	-DUINT8_TYPE=uint8_t -DINTPTR_TYPE=long

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
