# $NetBSD: Makefile,v 1.37 2009/08/26 19:57:58 sno Exp $

DISTNAME=	wmbiff-0.4.26
PKGREVISION=	8
CATEGORIES=	mail x11 windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wmbiff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/wmbiff/
COMMENT=	xbuffy like "mail-checker" for WindowMaker

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

EX_DIR=		${PREFIX}/share/examples/wmbiff

post-install:
	${INSTALL_DATA_DIR} ${EX_DIR}
	${INSTALL_DATA} ${WRKSRC}/wmbiff/sample.wmbiffrc ${EX_DIR}

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
