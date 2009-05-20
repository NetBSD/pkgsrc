# $NetBSD: Makefile,v 1.16 2009/05/20 23:20:39 zafer Exp $

DISTNAME=	jakdaw-0.0.4
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	audio xmms
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jakdaw.ucam.org/xmms/
COMMENT=	Very customizable XMMS plugin with nice effects

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
