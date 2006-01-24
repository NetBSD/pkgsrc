# $NetBSD: Makefile,v 1.26 2006/01/24 07:32:20 wiz Exp $

DISTNAME=	wmbiff-0.4.26
PKGREVISION=	2
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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
