# $NetBSD: Makefile,v 1.14 2019/08/22 12:23:44 ryoon Exp $

DISTNAME=	gtime-1.0-12
PKGNAME=	guardtime-1.0.12
PKGREVISION=	13
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
