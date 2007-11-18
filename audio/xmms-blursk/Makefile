# $NetBSD: Makefile,v 1.18 2007/11/18 10:23:23 wiz Exp $

DISTNAME=	Blursk-1.3
PKGNAME=	xmms-blursk-1.3
PKGREVISION=	2
CATEGORIES=	xmms audio
MASTER_SITES=	http://web.cecs.pdx.edu/~kirkenda/blursk/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} blursk-presets

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.cecs.pdx.edu/~kirkenda/blursk/
COMMENT=	Visualization plugin for XMMS inspired by "Blur Scope"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

post-install:
	${INSTALL_DATA} ${DISTDIR}/blursk-presets ${PREFIX}/share/xmms/blursk-presets

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
