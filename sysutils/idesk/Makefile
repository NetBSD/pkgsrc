# $NetBSD: Makefile,v 1.13 2005/07/21 16:29:57 wiz Exp $
#

DISTNAME=	idesk-0.7.2
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=idesk/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://idesk.sourceforge.net/
COMMENT=	Lightweight desktop icons handler

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--enable-libsn

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/idesk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/idesk

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
