# $NetBSD: Makefile,v 1.25 2019/01/05 21:46:05 schmonz Exp $

DISTNAME=	miredo-1.2.6
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/miredo/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.remlab.net/miredo/
COMMENT=	Teredo IPv6 tunneling
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-* NetBSD-[0-3].*-* SunOS-*-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-examplesdir=${EGDIR}
CONFIGURE_ARGS+=	--disable-sample-conf

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKG_SYSCONFSUBDIR?=	miredo
EGDIR=		${PREFIX}/share/examples/miredo
CONF_FILES=	${EGDIR}/miredo.conf ${PKG_SYSCONFDIR}/miredo.conf
CONF_FILES+=	${EGDIR}/miredo-server.conf \
		${PKG_SYSCONFDIR}/miredo-server.conf
CONF_FILES+=	${EGDIR}/client-hook ${PKG_SYSCONFDIR}/client-hook

RCD_SCRIPTS=	miredo

BUILD_DEFS+=	VARBASE

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
