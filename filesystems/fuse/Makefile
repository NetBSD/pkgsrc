# $NetBSD: Makefile,v 1.13 2023/09/07 19:38:14 vins Exp $
#

DISTNAME=	fuse-2.9.9
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

USE_TOOLS+=	gmake pkg-config
USE_TOOLS+=	autoconf automake autoreconf
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig

PKG_DOCS=	doc/how-fuse-works doc/kernel.txt
DOCDIR=		share/doc/${PKGBASE}

INSTALL_TARGET=		install-strip
INSTALLATION_DIRS+=	${DOCDIR}

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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
