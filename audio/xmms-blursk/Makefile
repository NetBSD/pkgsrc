# $NetBSD: Makefile,v 1.3 2003/07/13 06:51:18 grant Exp $

DISTNAME=	Blursk-1.3
PKGNAME=	xmms-blursk-1.3
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.cs.pdx.edu/~kirkenda/blursk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Visualization plugin for XMMS inspired by "Blur Scope"

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_X11=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
