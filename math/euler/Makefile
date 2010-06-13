# $NetBSD: Makefile,v 1.21 2010/06/13 22:44:55 wiz Exp $

DISTNAME=		euler-1.61.0
PKGNAME=		euler-1.61
EXTRACT_SUFX=		.tgz
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
