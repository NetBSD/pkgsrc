# $NetBSD: Makefile,v 1.37 2025/10/23 20:36:04 wiz Exp $

DISTNAME=	telepathy-haze-0.8.0
PKGREVISION=	22
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
