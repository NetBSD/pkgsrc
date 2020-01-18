# $NetBSD: Makefile,v 1.11 2020/01/18 21:50:50 jperkin Exp $

DISTNAME=	yafic-1.2.2
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yafic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.saddi.com/software/yafic/
COMMENT=	File integrity checker
LICENSE=	modified-bsd

GNU_CONFIGURE=	YES

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
