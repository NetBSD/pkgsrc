# $NetBSD: Makefile,v 1.2 2003/07/13 06:49:02 grant Exp $

DISTNAME=	Blursk-1.3
PKGNAME=	xmms-blursk-1.3
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.cs.pdx.edu/~kirkenda/blursk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.pdx.edu/~kirkenda/blursk/
COMMENT=	Visualization plugin for XMMS inspired by "Blur Scope"

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_X11=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
