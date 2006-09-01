# $NetBSD: Makefile,v 1.4 2006/09/01 19:53:47 rillig Exp $

DISTNAME=		wireshark-0.99.3
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.wireshark.org/download/src/ \
			${MASTER_SITE_SOURCEFORGE:=wireshark/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.wireshark.org/
COMMENT=		Network protocol analyzer

CONFLICTS+=		ethereal-[0-9]*

USE_LANGUAGES+=		c c++
USE_TOOLS+=		perl pkg-config

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

# Work arround for files missing in the 0.99.3 release archive.
# This and "${FILESDIR}/*.xpm" should be removed after the next update.
post-extract:
	${CP} ${FILESDIR}/*.xpm ${WRKSRC}/image/toolbar

# XXX avoid rebuild after dissector patch
pre-build:
	${TOUCH} ${WRKSRC}/epan/dissectors/register.c

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
