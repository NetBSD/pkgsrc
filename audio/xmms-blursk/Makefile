# $NetBSD: Makefile,v 1.15 2006/02/05 23:08:17 joerg Exp $

DISTNAME=	Blursk-1.3
PKGNAME=	xmms-blursk-1.3
PKGREVISION=	2
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.cs.pdx.edu/~kirkenda/blursk/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} blursk-presets

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Visualization plugin for XMMS inspired by "Blur Scope"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

post-install:
	${INSTALL_DATA} ${DISTDIR}/blursk-presets ${PREFIX}/share/xmms/blursk-presets

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
