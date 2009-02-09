# $NetBSD: Makefile,v 1.6 2009/02/09 22:56:23 joerg Exp $
#

DISTNAME=	wikipediafs-0.3
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wikipediafs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wikipediafs.sourceforge.net/
COMMENT=	FUSE filesystem for accessing the wikipedia

PYTHON_VERSIONS_ACCEPTED=	25 24

PYDISTUTILSPKG=		yes
PY_PATCHLIST=		yes

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	setup.py
SUBST_SED.config+=	-e "s|/usr/share/man/man1/|${PKGMANDIR}/man1/|g"
SUBST_MESSAGE.config=   Fixing paths.

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
