# $NetBSD: Makefile,v 1.6 2016/04/10 19:38:52 prlw1 Exp $

.include "../../devel/radare2/Makefile.common"

PKGNAME=	radare2-valabind-0.9.2
PKGREVISION=	3
DISTNAME=	valabind-0.9.2
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
