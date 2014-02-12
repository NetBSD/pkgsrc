# $NetBSD: Makefile,v 1.20 2014/02/12 23:18:20 tron Exp $

DISTNAME=	ettercap-NG-0.7.3
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ettercap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ettercap.sourceforge.net/
COMMENT=	Multipurpose sniffer/interceptor/logger for switched LAN
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

CONFLICTS=	ettercap-[0-9]*

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.1

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require
USE_LIBTOOL=		YES
USE_NCURSES=		YES # ncurses.h menu.h panel.h form.h
USE_OLD_DES_API=	YES
CPPFLAGS+=		-L${BUILDLINK_PREFIX.libnet11}/lib/libnet11

CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet11}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--disable-gtk

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure
SUBST_SED.conf+=	-e "s|@@LN_INC@@|${BUILDLINK_PREFIX.libnet11}/include/libnet11|g"
SUBST_SED.conf+=	-e "s|@@LN_LIB@@|${BUILDLINK_PREFIX.libnet11}/lib/libnet11|g"
SUBST_MESSAGE.conf=	Fixing configuration script.

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	YES
.endif

CONF_FILES=	${PREFIX}/share/examples/ettercap-NG/etter.conf \
		${PKG_SYSCONFDIR}/etter.conf

INSTALLATION_DIRS+=	 share/examples/ettercap-NG

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libnet11/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/etter.conf \
		${DESTDIR}${PREFIX}/share/examples/ettercap-NG

.include "../../mk/bsd.pkg.mk"
