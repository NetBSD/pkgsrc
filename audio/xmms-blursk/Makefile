# $NetBSD: Makefile,v 1.13 2005/12/07 15:02:31 joerg Exp $

DISTNAME=	Blursk-1.3
PKGNAME=	xmms-blursk-1.3
PKGREVISION=	1
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.cs.pdx.edu/~kirkenda/blursk/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} blursk-presets

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Visualization plugin for XMMS inspired by "Blur Scope"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA} ${DISTDIR}/blursk-presets ${PREFIX}/share/xmms/blursk-presets

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
