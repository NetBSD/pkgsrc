# $NetBSD: Makefile,v 1.8 2001/07/23 15:04:47 nra Exp $

DISTNAME=	WSoundPrefs-1.1.1
PKGNAME=	wsoundprefs-1.1.1
CATEGORIES=	audio wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	WSoundServer configuration utility

DEPENDS+=	wsoundserver-0.4.0:../../audio/wsoundserver

USE_X11BASE=	YES
USE_IMAKE=	YES
USE_BUILDLINK_ONLY=YES

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/libproplist/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
