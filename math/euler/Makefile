# $NetBSD: Makefile,v 1.42 2016/08/03 10:23:06 adam Exp $

DISTNAME=		euler-1.61.0
PKGNAME=		euler-1.61
EXTRACT_SUFX=		.tgz
PKGREVISION=		22
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
