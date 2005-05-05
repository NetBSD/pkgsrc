# $NetBSD: Makefile,v 1.1.1.1 2005/05/05 19:34:44 xtraeme Exp $

DISTNAME=	ettercap-NG-0.7.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ettercap/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://ettercap.sourceforge.net/
COMMENT=	Multipurpose sniffer/interceptor/logger for switched LAN

CONFLICTS=	ettercap-[0-9]*

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.8.1

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
USE_NCURSES=		# ncurses.h menu.h panel.h form.h
USE_OLD_DES_API=	YES

CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--disable-gtk

CONF_FILES=	${PREFIX}/share/examples/ettercap-NG/etter.conf \
		${PKG_SYSCONFDIR}/etter.conf

PKG_OPTIONS_VAR=        PKG_OPTIONS.ettercap-NG
PKG_SUPPORTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.	include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk
.endif

# See PR# 28772 about INSTALL_STRIPPED=NO being ignored on certain platforms
.if ${OPSYS} == "Darwin"
_STRIPFLAG_CC=
_STRIPFLAG_INSTALL=
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libnet11/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ettercap-NG
	${INSTALL_DATA} ${WRKSRC}/share/etter.conf \
		${PREFIX}/share/examples/ettercap-NG

.include "../../mk/bsd.pkg.mk"
