# $NetBSD: Makefile,v 1.3 2026/06/04 17:04:20 gdt Exp $
#

DISTNAME=	fuse-3.18.2
PKGNAME=	${DISTNAME:S/fuse/fuse3/}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=	libfuse
GITHUB_RELEASE=	${PKGBASE}-${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/libfuse/libfuse
COMMENT=		Filesystem in Userspace (version 3)
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

# The FUSE library requires operating system support for /dev/fuse.
ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-* NetBSD-*-*

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	doc/mount.fuse3.8 util/fuse.conf
SUBST_SED.conf+=	-e "s:/etc/fuse.conf:${PKG_SYSCONFDIR}/fuse.conf:g"
SUBST_MESSAGE.conf=	Setting default configuration file path for FUSE

PKG_DOCS=	doc/README.* doc/*.txt
DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}
INCLUDEDIR=	include/fuse3

.include "../../mk/bsd.prefs.mk"

MESON_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
		-Dexamples=true \
		-Dtests=true \
		-Dutils=true

.if ${OPSYS} == "Linux"
MESON_ARGS+=	-Dinitscriptdir=${PREFIX}/${EGDIR} \
		-Dudevrulesdir=${PREFIX}/${EGDIR} \
		-Denable-io-uring=true
.endif

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/fuse3.pc

CONF_FILES+=		${EGDIR}/fuse.conf ${PKG_SYSCONFDIR}/fuse.conf

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${INCLUDEDIR}

SPECIAL_PERMS+=		bin/fusermount3 ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h	\
		${DESTDIR}${PREFIX}/${INCLUDEDIR}
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|}	\
		${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/util/fuse.conf \
		${DESTDIR}${PREFIX}/${EGDIR}

.if ${OPSYS} == "Linux"
.  include "../../devel/liburing/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
