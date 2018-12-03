# $NetBSD: Makefile,v 1.201 2018/12/03 15:35:15 adam Exp $

DISTNAME=	wireshark-2.6.5
CATEGORIES=	net
MASTER_SITES=	https://www.wireshark.org/download/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.wireshark.org/
COMMENT=	Network protocol analyzer
LICENSE=	gnu-gpl-v2

CONFLICTS+=		ethereal-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config yacc lex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-static=no
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ENV+=		ac_cv_path_YACCDUMMY=${TOOLS_PATH.yacc}
CONFIGURE_ENV+=		ac_cv_path_LEXDUMMY=${TOOLS_PATH.lex}
PKGCONFIG_OVERRIDE+=	wireshark.pc.in
SHLIBTOOL_OVERRIDE=	# empty

CHECK_PORTABILITY_SKIP+=	packaging/macosx/*/*

PTHREAD_OPTS+=		require

PYTHON_FOR_BUILD_ONLY=		yes
REPLACE_PYTHON+=		help/faq.py
REPLACE_PYTHON+=		tools/asn2deb
REPLACE_PYTHON+=		tools/asn2wrs.py
REPLACE_PYTHON+=		tools/dfilter-test.py
REPLACE_PYTHON+=		tools/ftsanity.py
REPLACE_PYTHON+=		tools/html2text.py
REPLACE_PYTHON+=		tools/idl2deb
REPLACE_PYTHON+=		tools/indexcap.py
REPLACE_PYTHON+=		tools/msnchat
REPLACE_PYTHON+=		tools/ncp2222.py
REPLACE_PYTHON+=		tools/netscreen2dump.py
REPLACE_PYTHON+=		tools/pkt-from-core.py
REPLACE_PYTHON+=		tools/rdps.py

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

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsmi/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
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
