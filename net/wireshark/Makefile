# $NetBSD: Makefile,v 1.5.2.1 2007/02/07 16:05:21 salo Exp $

DISTNAME=		wireshark-0.99.5
CATEGORIES=		net
MASTER_SITES=		http://www.wireshark.org/download/src/ \
			${MASTER_SITE_SOURCEFORGE:=wireshark/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.wireshark.org/
COMMENT=		Network protocol analyzer

CONFLICTS+=		ethereal-[0-9]*

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake perl pkg-config

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=        --enable-static=no
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_PREFIX.gtk2}
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-net-snmp
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}

PTHREAD_OPTS+=		require

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-[567].*-*)
USE_BUILTIN.libpcap=	no
.endif

SUBST_CLASSES+=		shell
SUBST_STAGE.shell=	post-build
SUBST_MESSAGE.shell=	Replacing @SHELL@ with a proper shell.
SUBST_FILES.shell=	idl2wrs
SUBST_SED.shell=	-e 's,@SHELL@,${SHELL},g'

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
