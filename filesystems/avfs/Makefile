# $NetBSD: Makefile,v 1.1 2026/04/22 17:47:50 vins Exp $

DISTNAME=	avfs-1.3.0
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=avf/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://avf.sourceforge.net/
COMMENT=	Virtual File System library
# FUSE daemon is licensed as GPLv2, shared library is LGPLv2
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run perl:run pkg-config tar

PKGCONFIG_OVERRIDE+=	pkgconfig/avfs.pc.in

REPLACE_BASH=	extfs/uimg scripts/umountavfs scripts/mountavfs
REPLACE_SH=	ltmain.sh

CPPFLAGS.NetBSD+=	-DFUSE_FILL_DIR_DEFAULTS=0	# ReFUSE lacks this

CONFIGURE_ENV+=		PERL=${PERL5:Q} \
			LIBTOOL=${LIBTOOL:Q}
CONFIGURE_ARGS+=	--with-sysroot=${PREFIX} \
			--with-pkgconfigdir=${PREFIX}/lib/pkgconfig \
			--enable-library \
			--with-xz \
			--with-system-zlib \
			--with-system-bzlib

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
