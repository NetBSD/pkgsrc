# $NetBSD: Makefile,v 1.12 2003/11/06 17:11:59 gavan Exp $

DISTNAME=	libsigc++-1.2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

BUILD_DEPENDS=		m4>=1.4:../../devel/m4

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_GCC_SHLIB=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/sigc++-1.2.pc.in

CONFIGURE_ENV+=		ac_cv_prog_M4=${LOCALBASE}/bin/gm4

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
