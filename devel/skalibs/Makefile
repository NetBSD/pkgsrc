# $NetBSD: Makefile,v 1.15 2021/12/26 16:42:42 nros Exp $

DISTNAME=		skalibs-2.11.1.0
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		cfkoch@edgebsd.org
HOMEPAGE=		https://skarnet.org/software/skalibs/
COMMENT=		The skarnet.org C system programming library
LICENSE=		isc

USE_LANGUAGES=		c
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

CPPFLAGS.NetBSD=	-D_NETBSD_SOURCE

INSTALLATION_DIRS=	include/skalibs lib/skalibs/sysdeps

post-install:
	${LN} -sf ../libskarnet.a ${DESTDIR}${PREFIX}/lib/skalibs/libskarnet.a

.include "../../mk/bsd.pkg.mk"
