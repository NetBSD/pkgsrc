# $NetBSD: Makefile,v 1.14 2004/01/24 13:55:31 grant Exp $

DISTNAME=	wmbiff-0.4.19
PKGREVISION=	1
CATEGORIES=	mail x11 windowmaker
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=wmbiff/)

MAINTAINER=	tron@zhadum.de
HOMEPAGE=	http://sourceforge.net/projects/wmbiff/
COMMENT=	xbuffy like "mail-checker" for WindowMaker

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make

EX_DIR=		${PREFIX}/share/examples/wmbiff

post-install:
	${INSTALL_DATA_DIR} ${EX_DIR}
	${INSTALL_DATA} ${WRKSRC}/wmbiff/sample.wmbiffrc ${EX_DIR}

.include "../../graphics/xpm/buildlink2.mk"
.include "../../wm/windowmaker/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
