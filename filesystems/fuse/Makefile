# $NetBSD: Makefile,v 1.17 2026/05/06 17:08:48 vins Exp $
#

DISTNAME=	fuse-3.18.2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=	libfuse
GITHUB_RELEASE=	${PKGBASE}-${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/libfuse/libfuse
COMMENT=		Filesystem in Userspace
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

# FUSE the implementation only builds on Linux and FreeBSD.
ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-* NetBSD-*-*
# On NetBSD 4.99 after 2007-02, /usr/lib/librefuse provides the FUSE
# interface expected by filesystem implementations and therefore this
# implementation is not needed. This FUSE implementation can also be
# used with the perfuse package on NetBSD.

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

AUTO_MKDIRS=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h	\
		${DESTDIR}${PREFIX}/include/fuse
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|}	\
		${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/util/fuse.conf \
		${DESTDIR}${PREFIX}/${EGDIR}

.if ${OPSYS} == "Linux"
.  include "../../devel/liburing/buildlink3.mk"
	${RUN}${CHMOD} -w	${DESTDIR}${PREFIX}/bin/fusermount
.elif ${OPSYS} == "NetBSD"
.  include "../../filesystems/perfuse/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
