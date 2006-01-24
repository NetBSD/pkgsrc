# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:35 wiz Exp $
#

DISTNAME=	idesk-0.7.2
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=idesk/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://idesk.sourceforge.net/
COMMENT=	Lightweight desktop icons handler

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-libsn

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/idesk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/idesk

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
