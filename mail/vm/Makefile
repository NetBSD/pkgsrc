# $NetBSD: Makefile,v 1.44 2018/11/29 00:36:23 markd Exp $

DISTNAME=	vm-8.2.0b
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	https://launchpad.net/vm/8.2.x/8.2.0b/+download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/vm
COMMENT=	VM (View Mail) is an advanced mail user agent for Emacs

USE_TOOLS+=	makeinfo gmake gtar
GNU_CONFIGURE=	yes
INFO_FILES=	yes

MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}
MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/vm
MAKE_ENV+=	INFODIR=${INFODIR:Q}
MAKE_ENV+=	PIXMAPDIR=${PIXMAPDIR:Q}
MAKE_ENV+=	BINDIR=${PREFIX:Q}/bin
PLIST_SUBST+=	PIXMAPDIR=${PIXMAPDIR:S/^${PREFIX}\///:Q}

INSTALLATION_DIRS=	bin ${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/vm	\
			${PIXMAPDIR}

PIXMAPDIR=		${PIXMAPDIR.${EMACS_FLAVOR}}
PIXMAPDIR.emacs=	${PREFIX:Q}/share/vm/pixmaps
PIXMAPDIR.xemacs=	${EMACS_LISPPREFIX:H}/etc/vm

.include "../../editors/emacs/modules.mk"

.include "../../misc/bbdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
