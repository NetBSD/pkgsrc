# $NetBSD: Makefile,v 1.19 2004/04/24 22:46:08 jlam Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
PKGREVISION=	3
CATEGORIES=	audio wm windowmaker
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	WSoundServer configuration utility

USE_BUILDLINK3=		YES
USE_IMAKE=		YES
USE_X11BASE=		YES

.include "../../audio/wsoundserver/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
