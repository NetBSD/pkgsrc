# $NetBSD: Makefile,v 1.40 2026/09/27 11:35:15 tnn Exp $

DISTNAME=	telepathy-haze-0.8.0
PKGREVISION=	25
CATEGORIES=	chat
MASTER_SITES=	https://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://telepathy.freedesktop.org/doc/telepathy-haze/
COMMENT=	Libpurple connection manager for Telepathy
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake pkg-config
PYTHON_VERSIONS_ACCEPTED= 27 # as of 0.8.0

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
