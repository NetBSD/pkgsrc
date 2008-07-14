# $NetBSD: Makefile,v 1.18 2008/07/14 12:55:58 joerg Exp $
#

DISTNAME=	infinity-0.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	xmms audio
MASTER_SITES=	http://julien.carme.free.fr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://julien.carme.free.fr/infinite.html
COMMENT=	Psychedelic visualization plug-in for xmms

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
