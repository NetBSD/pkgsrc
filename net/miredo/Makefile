# $NetBSD: Makefile,v 1.14 2007/07/08 12:35:10 wiz Exp $

DISTNAME=	miredo-1.0.6
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/miredo/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.remlab.net/miredo/
COMMENT=	Teredo IPv6 tunneling

NOT_FOR_PLATFORM=	Interix-*-* NetBSD-[0-3]*-* SunOS-*-*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/miredo
CONF_FILES=	${EGDIR}/miredo.conf-dist ${PKG_SYSCONFDIR}/miredo.conf
CONF_FILES+=	${EGDIR}/miredo-server.conf-dist \
		${PKG_SYSCONFDIR}/miredo-server.conf
CONF_FILES+=	${EGDIR}/isatapd.conf-dist ${PKG_SYSCONFDIR}/isatapd.conf

CONFIGURE_ARGS+=	--enable-examplesdir=${EGDIR} --disable-sample-conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
