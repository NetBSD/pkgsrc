# $NetBSD: Makefile,v 1.16 2023/09/09 10:23:00 vins Exp $
#

DISTNAME=	fuse-2.9.9
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=	libfuse
GITHUB_TAG=	refs/tags/${DISTNAME}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/libfuse/libfuse
COMMENT=		Filesystem in Userspace
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		yes

# FUSE the implementation only builds on Linux and FreeBSD.
ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-* NetBSD-*-*
# On NetBSD 4.99 after 2007-02, /usr/lib/librefuse provides the FUSE
# interface expected by filesystem implementations and therefore this
# implementation is not needed. This FUSE implementation can also be
# used with the perfuse package on NetBSD.

USE_TOOLS+=	gmake pkg-config gettext
USE_TOOLS+=	autoconf automake autoreconf
USE_LIBTOOL=	yes

TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ENV+=	MOUNT_FUSE_PATH=${PREFIX}/sbin
CONFIGURE_ENV+=	UDEV_RULES_PATH=${PREFIX}/${EGDIR}
CONFIGURE_ENV+=	INIT_D_PATH=${PREFIX}/${EGDIR}
.endif

PKG_DOCS=	doc/how-fuse-works doc/kernel.txt
DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}

INSTALL_TARGET=		install-strip
INSTALLATION_DIRS+=	${DOCDIR}

.if ${OPSYS} == "Linux"
INSTALLATION_DIRS+=	sbin ${EGDIR}
.endif

WRKSRC=	${WRKDIR}/libfuse-${DISTNAME}

pre-configure:
	${RUN}${CP} ${FILESDIR}/config.rpath ${WRKSRC}
	${RUN}cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${SH} ./makeconf.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h	\
		${DESTDIR}${PREFIX}/include/fuse
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|}	\
		${DESTDIR}${PREFIX}/${DOCDIR}

.if ${OPSYS} == "Linux"
	${RUN}${CHMOD} -w	${DESTDIR}${PREFIX}/bin/fusermount
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
