# $NetBSD: Makefile,v 1.23 2007/12/02 00:01:08 wiz Exp $

DISTNAME=	lincity-1.12.1
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lincity/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://lincity.sourceforge.net/
COMMENT=	Free clone of SimCity for X11

USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CHECK_INTERPRETER_SKIP+=	share/lincity/icons/*

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/icons
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/messages
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/opening

post-install:
	${LN} -sf lincity.6 ${PREFIX}/${PKGMANDIR}/man6/xlincity.6

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
