# $NetBSD: Makefile,v 1.10 2003/05/02 11:54:38 wiz Exp $

DISTNAME=	libsigc++-1.2.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	type-safe callback system for C++ programs

BUILD_DEPENDS=		m4>=1.4:../../devel/m4

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/scripts/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/sigc++-1.2.pc.in

CONFIGURE_ENV+=		ac_cv_prog_M4=${LOCALBASE}/bin/gm4

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
