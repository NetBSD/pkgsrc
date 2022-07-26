# $NetBSD: Makefile,v 1.276 2022/07/26 22:54:51 tnn Exp $

DISTNAME=	wireshark-3.6.6
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://www.wireshark.org/download/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.wireshark.org/
COMMENT=	Network protocol analyzer
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ethereal-[0-9]*

USE_CMAKE=		yes
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DENABLE_APPLICATION_BUNDLE=OFF
CMAKE_ARGS+=		-DVCSVERSION_OVERRIDE=${PKGVERSION_NOREV}
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Asciidoctor=TRUE
CMAKE_ARG_PATH=		..
CONFIGURE_DIRS=		build

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl pkg-config bison lex
PKGCONFIG_OVERRIDE+=	wireshark.pc.in

CHECK_PORTABILITY_SKIP+=	packaging/macosx/*/*
CHECK_PORTABILITY_SKIP+=	packaging/macosx/osx-app.sh.in
CHECK_PORTABILITY_SKIP+=	tools/bsd-setup.sh

PTHREAD_OPTS+=		require

PYTHON_VERSIONS_INCOMPATIBLE=	27 # Python 2.7 is not supported
PYTHON_FOR_BUILD_ONLY=		yes
REPLACE_PYTHON+=		tools/asn2deb
REPLACE_PYTHON+=		tools/asn2wrs.py
REPLACE_PYTHON+=		tools/html2text.py
REPLACE_PYTHON+=		tools/idl2deb
REPLACE_PYTHON+=		tools/indexcap.py
REPLACE_PYTHON+=		tools/msnchat
REPLACE_PYTHON+=		tools/ncp2222.py
REPLACE_PYTHON+=		tools/netscreen2dump.py
REPLACE_PYTHON+=		tools/pkt-from-core.py
REPLACE_PYTHON+=		tools/rdps.py

CFLAGS.SunOS+=		-D__EXTENSIONS__ # for getc_unlocked(3)

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-[567].*-*)
USE_BUILTIN.libpcap=	no
.endif

# Extra post install targets are in options.mk
post-install: ${POST_INSTALL_TARGETS}

# wireshark no longer builds with NetBSD 3.x provided zlib
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.1

# wireshark uses gdk_pixbuf_new_from_inline which is deprecated, but asks
# to hide deprecated prototypes. This leads to pointer truncation.
# gui_utils.c:514:12: warning: incompatible integer to pointer conversion
# assigning to 'GdkPixbuf *' (aka 'struct _GdkPixbuf *') from 'int'
# [-Wint-conversion]
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED

.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsmi/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
