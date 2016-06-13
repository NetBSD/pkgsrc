# $NetBSD: Makefile,v 1.7 2016/06/13 12:26:11 wiz Exp $

.include "../../devel/radare2/Makefile.common"

PKGNAME=	radare2-${DISTNAME}
DISTNAME=	valabind-0.10.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Reverse engineering framework (language bindings interface)
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	GIT_TIP=

.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
