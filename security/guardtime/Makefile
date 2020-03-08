# $NetBSD: Makefile,v 1.17 2020/03/08 16:51:08 wiz Exp $

DISTNAME=	gtime-1.0-12
PKGNAME=	guardtime-1.0.12
PKGREVISION=	16
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
