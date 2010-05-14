# $NetBSD: Makefile,v 1.16 2010/05/14 06:18:48 pettai Exp $

DISTNAME=	miredo-1.1.7
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/miredo/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.remlab.net/miredo/
COMMENT=	Teredo IPv6 tunneling

NOT_FOR_PLATFORM=	Interix-*-* NetBSD-[0-3]*-* SunOS-*-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-examplesdir=${EGDIR}
CONFIGURE_ARGS+=	--disable-sample-conf

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=		${PREFIX}/share/examples/miredo
CONF_FILES=	${EGDIR}/miredo.conf ${PKG_SYSCONFDIR}/miredo.conf
CONF_FILES+=	${EGDIR}/miredo-server.conf \
		${PKG_SYSCONFDIR}/miredo-server.conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
