# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:06 tv Exp $

DISTNAME=		kmp-0.01
PKGREVISION=	1
CATEGORIES=		audio
MASTER_SITES=		http://www.threadbox.net/files/KMP/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://www.threadbox.net/kmp.php
COMMENT=		Qt client for the Music Player Daemon

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c++
USE_LIBTOOL=		yes
USE_X11=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	${PREFIX}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
