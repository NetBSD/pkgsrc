# $NetBSD: Makefile,v 1.12 2002/03/13 17:36:38 fredb Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
PKGREVISION=	1
CATEGORIES=	audio wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	WSoundServer configuration utility

USE_CONFIG_WRAPPER=	YES
USE_X11BASE=		YES
USE_IMAKE=		YES

.include "../../audio/wsoundserver/buildlink.mk"
.include "../../wm/windowmaker/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
