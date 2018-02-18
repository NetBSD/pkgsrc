# $NetBSD: Makefile,v 1.10 2018/02/18 18:04:16 kamil Exp $

.include "../../devel/radare2/Makefile.common"

BROKEN=		Incompatible vala version

GITHUB_PROJECT=	valabind
PKGNAME=	radare2-${DISTNAME}
DISTNAME=	valabind-1.5.0
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
