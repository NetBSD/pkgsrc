# $NetBSD: Makefile,v 1.8 2019/04/26 13:13:45 maya Exp $

DISTNAME=	telepathy-haze-0.8.0
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	jaapb@NetBSD.org
#HOMEPAGE=	https://telepathy.freedesktop.org/doc/telepathy-haze/
COMMENT=	Libpurple connection manager for Telepathy
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 0.8.0

.include "../../chat/libpurple/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
