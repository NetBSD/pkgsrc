# $NetBSD: Makefile,v 1.24 2018/02/06 13:33:36 jperkin Exp $

DISTNAME=	chmlib-0.40
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.jedrea.com/chmlib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jedrea.com/chmlib/
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	kchm-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-io64
CONFIGURE_ARGS+=	--enable-examples

LIBS.SunOS+=	-lnsl -lsocket

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-pthread
.endif

.include "../../mk/bsd.pkg.mk"
