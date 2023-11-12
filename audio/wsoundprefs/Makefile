# $NetBSD: Makefile,v 1.62 2023/11/12 13:20:44 wiz Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
PKGREVISION=	30
CATEGORIES=	audio wm windowmaker
MASTER_SITES=	# ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	WSoundServer configuration utility
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
USE_IMAKE=	yes
BROKEN_GETTEXT_DETECTION=	yes

LDFLAGS.SunOS+=	-lwraster

.include "../../audio/wsoundserver/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
