# $NetBSD: Makefile,v 1.13 2002/08/31 03:08:59 wiz Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
PKGREVISION=	1
CATEGORIES=	audio wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	WSoundServer configuration utility

USE_BUILDLINK2=		YES
USE_IMAKE=		YES
USE_X11BASE=		YES

.include "../../audio/wsoundserver/buildlink2.mk"
.include "../../wm/windowmaker/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
