# $NetBSD: Makefile,v 1.31 2007/02/06 12:24:50 joerg Exp $

DISTNAME=	wmbiff-0.4.26
PKGREVISION=	5
CATEGORIES=	mail x11 windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wmbiff/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/wmbiff/
COMMENT=	xbuffy like "mail-checker" for WindowMaker

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

EX_DIR=		${PREFIX}/share/examples/wmbiff

post-install:
	${INSTALL_DATA_DIR} ${EX_DIR}
	${INSTALL_DATA} ${WRKSRC}/wmbiff/sample.wmbiffrc ${EX_DIR}

.include "../../security/gnutls/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
