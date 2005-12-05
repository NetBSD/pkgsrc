# $NetBSD: Makefile,v 1.12 2005/12/05 20:49:50 rillig Exp $

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

.if !exists(${X11BASE}/include/X11/extensions/Xvlib.h)
PKG_FAIL_REASON+=	"${PKGNAME} requires libXv.a"
.endif

post-install:
	${INSTALL_DATA} ${DISTDIR}/blursk-presets ${PREFIX}/share/xmms/blursk-presets

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
