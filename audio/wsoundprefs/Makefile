# $NetBSD: Makefile,v 1.16 2003/07/17 21:23:45 grant Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
PKGREVISION=	2
CATEGORIES=	audio wm windowmaker
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	WSoundServer configuration utility

USE_BUILDLINK2=		YES
USE_IMAKE=		YES
USE_X11BASE=		YES

.include "../../audio/wsoundserver/buildlink2.mk"
.include "../../wm/windowmaker/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
