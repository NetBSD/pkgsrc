# $NetBSD: Makefile,v 1.21 2026/06/03 23:27:17 gdt Exp $
#

DISTNAME=	fuse-2.9.9
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=	libfuse
GITHUB_TAG=	${PKGBASE}-${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/libfuse/libfuse
COMMENT=		Filesystem in Userspace (version 2)
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

# The FUSE library requires operating system support for /dev/fuse.
ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-* NetBSD-*-*

GNU_CONFIGURE=		yes

USE_TOOLS+=	gmake pkg-config gettext
USE_TOOLS+=	autoconf automake autoreconf
USE_LIBTOOL=	yes

TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

PKG_DOCS=	doc/how-fuse-works doc/kernel.txt
DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}
INCLUDEDIR=	include/fuse

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig

.if ${OPSYS} == "Linux"
CONFIGURE_ENV+=	MOUNT_FUSE_PATH=${PREFIX}/sbin
CONFIGURE_ENV+=	UDEV_RULES_PATH=${PREFIX}/${EGDIR}
CONFIGURE_ENV+=	INIT_D_PATH=${PREFIX}/${EGDIR}
.endif

INSTALL_TARGET=		install-strip
INSTALLATION_DIRS+=	${DOCDIR} ${INCLUDEDIR}

.if ${OPSYS} == "Linux"
INSTALLATION_DIRS+=	sbin ${EGDIR}
.endif

pre-configure:
	${RUN}${CP} ${FILESDIR}/config.rpath ${WRKSRC}
	${RUN}cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${SH} ./makeconf.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h	\
		${DESTDIR}${PREFIX}/${INCLUDEDIR}
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|}	\
		${DESTDIR}${PREFIX}/${DOCDIR}

.if ${OPSYS} == "Linux"
	${RUN}${CHMOD} -w	${DESTDIR}${PREFIX}/bin/fusermount
.endif

.if ${OPSYS} == "NetBSD"
.  include "../../filesystems/perfuse/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
