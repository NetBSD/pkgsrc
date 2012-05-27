# $NetBSD: Makefile,v 1.76.2.2 2012/05/27 12:16:52 spz Exp $

DISTNAME=		wireshark-1.6.8
CATEGORIES=		net
MASTER_SITES=		http://www.wireshark.org/download/src/ \
			${MASTER_SITE_SOURCEFORGE:=wireshark/}
EXTRACT_SUFX=		.tar.bz2

OWNER=			tron@NetBSD.org
HOMEPAGE=		http://www.wireshark.org/
COMMENT=		Network protocol analyzer
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		ethereal-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl pkg-config yacc lex

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty
CHECK_PORTABILITY_SKIP+= packaging/macosx/*/*

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static=no
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ENV+=		ac_cv_path_YACCDUMMY=${TOOLS_PATH.yacc}
CONFIGURE_ENV+=		ac_cv_path_LEXDUMMY=${TOOLS_PATH.lex}

PTHREAD_OPTS+=		require

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-[567].*-*)
USE_BUILTIN.libpcap=	no
.endif

# wireshark no longer builds with NetBSD 3.x provided zlib
BUILDLINK_API_DEPENDS.zlib=zlib>=1.2.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libsmi/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
