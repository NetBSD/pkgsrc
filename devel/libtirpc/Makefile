# $NetBSD: Makefile,v 1.1 2023/08/29 11:28:40 vins Exp $

DISTNAME=	libtirpc-1.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libtirpc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	als@thangorodrim.ch
HOMEPAGE=	https://sourceforge.net/projects/libtirpc/
COMMENT=	Port of SUNs Transport-Independent RPC library
LICENSE=	original-bsd

ONLY_FOR_PLATFORM=	Linux-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf autoreconf automake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples/${PKGBASE}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/bindresvport.blacklist \
		${PKG_SYSCONFDIR}/bindresvport.blacklist
CONF_FILES+=	${EGDIR}/netconfig ${PKG_SYSCONFDIR}/netconfig

PKGCONFIG_OVERRIDE+=	libtirpc.pc.in

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
