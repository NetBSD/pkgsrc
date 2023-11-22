# $NetBSD: Makefile,v 1.12 2023/11/22 19:46:10 wiz Exp $

DISTNAME=		sshfs-3.7.4a
PKGNAME=		fuse-${DISTNAME}
CATEGORIES=		filesystems
#MASTER_SITES=		${MASTER_SITE_GITHUB:=libfuse/}
MASTER_SITES=		${MASTER_SITE_GITHUB:=deadbeefsociety/}
GITHUB_PROJECT=		sshfs
GITHUB_RELEASE=		${DISTNAME}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deadbeefsociety/sshfs/
COMMENT=	File system client based on the SFTP protocol
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

SUBST_CLASSES+=		rst2man
SUBST_STAGE.rst2man=	pre-configure
SUBST_FILES.rst2man+=	meson.build
SUBST_SED.rst2man+=	-e "s,rst2man.py,rst2man-${PYVERSSUFFIX},g"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
