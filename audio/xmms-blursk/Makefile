# $NetBSD: Makefile,v 1.1.1.1 2003/07/13 05:03:35 mrg Exp $

DISTNAME=	Blursk-1.3
PKGNAME=	xmms-blursk-1.3
CATEGORIES=	xmms audio
MASTER_SITES=	http://www.cs.pdx.edu/~kirkenda/blursk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.pdx.edu/~kirkenda/blursk/
COMMENT=	Visualization plugin for XMMS inspired by "Blur Scope"

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
