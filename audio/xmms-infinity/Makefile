# $NetBSD: Makefile,v 1.11 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	infinity-0.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	xmms audio
MASTER_SITES=	http://julien.carme.free.fr/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://julien.carme.free.fr/infinite.html
COMMENT=	Psychedelic visualization plug-in for xmms

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
