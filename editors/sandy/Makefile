# $NetBSD: Makefile,v 1.13 2026/08/04 20:28:53 wiz Exp $

DISTNAME=	sandy-0.4
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oldgit.suckless.org/sandy/file/README.html
COMMENT=	Sandy is an ncurses text editor
LICENSE=	mit

SUBST_CLASSES=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		config.mk
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/usr/include,${BUILDLINK_PREFIX.ncurses}/include,g'
SUBST_SED.fix-paths+=		-e 's,/usr/lib,${BUILDLINK_PREFIX.ncurses}/lib -Wl\,-R${BUILDLINK_PREFIX.ncurses}/lib,g'
SUBST_SED.fix-paths+=		-e 's,share/man,${PKGMANDIR},g'

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
