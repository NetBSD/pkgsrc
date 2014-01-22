# $NetBSD: Makefile,v 1.13 2014/01/22 07:19:45 wiz Exp $

DISTNAME=	wikipediafs-0.3
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wikipediafs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wikipediafs.sourceforge.net/
COMMENT=	FUSE filesystem for accessing the wikipedia

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-fuse-bindings
EGG_NAME=	wikipediafs-0.1

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	setup.py
SUBST_SED.config+=	-e "s|/usr/share/man/man1/|${PKGMANDIR}/man1/|g"
SUBST_MESSAGE.config=   Fixing paths.

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
