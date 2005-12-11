# $NetBSD: Makefile,v 1.14 2005/12/11 09:40:38 wiz Exp $
#

DISTNAME=	infinity-0.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	xmms audio
MASTER_SITES=	http://julien.carme.free.fr/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://julien.carme.free.fr/infinite.html
COMMENT=	Psychedelic visualization plug-in for xmms

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
