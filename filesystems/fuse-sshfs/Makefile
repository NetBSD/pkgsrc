# $NetBSD: Makefile,v 1.16 2026/05/10 12:30:36 vins Exp $

DISTNAME=		sshfs-3.7.5
PKGNAME=		fuse-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		filesystems
MASTER_SITES=		${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=		sshfs
GITHUB_RELEASE=		${DISTNAME}
EXTRACT_SUFX=		.tar.xz
EXTRACT_USING=		bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deadbeefsociety/sshfs/
COMMENT=	File system client based on the SFTP protocol
LICENSE=	gnu-gpl-v2

# Cannot restore extended attributes: com.apple.provenance
EXTRACT_OPTS_TAR.${DISTNAME}${EXTRACT_SUFX}=	--no-xattr

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config
USE_FUSE3=	yes

TOOL_DEPENDS+=  ${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

PYTHON_FOR_BUILD_ONLY=          tool
PYTHON_VERSIONS_INCOMPATIBLE=   27

.include "../../mk/bsd.prefs.mk"

.if !empty(LP32PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@)
CFLAGS+=	-D_FILE_OFFSET_BITS=64
.endif

SUBST_CLASSES+=		rst2man
SUBST_STAGE.rst2man=	pre-configure
SUBST_FILES.rst2man+=	meson.build
SUBST_SED.rst2man+=	-e "s,rst2man.py,rst2man-${PYVERSSUFFIX},g"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
