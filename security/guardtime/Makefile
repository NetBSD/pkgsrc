# $NetBSD: Makefile,v 1.10 2018/08/16 18:55:09 adam Exp $

DISTNAME=	gtime-1.0-12
PKGNAME=	guardtime-1.0.12
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://download.guardtime.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.guardtime.com/
COMMENT=	Command line client for GuardTime keyless signature service
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../security/libguardtime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
