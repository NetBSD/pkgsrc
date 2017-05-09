# $NetBSD: Makefile,v 1.39 2017/05/09 15:32:53 jperkin Exp $

DISTNAME=	trafshow-5.2.3
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	# ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://soft.risp.ru/trafshow/index.shtml
COMMENT=	Full screen visualization of the network traffic

BUILD_TARGET=	trafshow
GNU_CONFIGURE=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.trafshow
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif

CFLAGS.Darwin+=	-DBIND_8_COMPAT

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/trafshow

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow \
	    ${DESTDIR}${PREFIX}/share/examples/trafshow/trafshow

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.1
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
