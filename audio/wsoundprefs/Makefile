# $NetBSD: Makefile,v 1.50 2014/05/15 14:41:45 adam Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
PKGREVISION=	23
CATEGORIES=	audio wm windowmaker
MASTER_SITES=	# ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	WSoundServer configuration utility

USE_IMAKE=		yes
BROKEN_GETTEXT_DETECTION=	yes

.include "../../audio/wsoundserver/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
