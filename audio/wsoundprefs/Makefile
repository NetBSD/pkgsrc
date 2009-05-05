# $NetBSD: Makefile,v 1.31 2009/05/05 18:51:56 zafer Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
PKGREVISION=	7
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
.include "../../mk/bsd.pkg.mk"
