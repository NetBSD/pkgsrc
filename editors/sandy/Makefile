# $NetBSD: Makefile,v 1.10 2024/05/06 08:27:52 jperkin Exp $

DISTNAME=	sandy-0.4
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tools.suckless.org/sandy
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

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
