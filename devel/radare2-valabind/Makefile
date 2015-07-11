# $NetBSD: Makefile,v 1.2 2015/07/11 15:05:57 khorben Exp $

.include "../../devel/radare2/Makefile.common"

PKGNAME=	radare2-valabind-0.9.2
PKGREVISION=	1
DISTNAME=	valabind-0.9.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radare/radare2-valabind/archive/}

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
