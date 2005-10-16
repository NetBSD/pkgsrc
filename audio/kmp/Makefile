# $NetBSD: Makefile,v 1.6 2005/10/16 15:19:46 wiz Exp $

DISTNAME=		kmp-0.01
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.threadbox.net/code/files/kmp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://www.threadbox.net/index.php/code/kmp/
COMMENT=		Qt client for the Music Player Daemon

USE_LANGUAGES=		c++
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	${PREFIX}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
