# $NetBSD: Makefile,v 1.8 2005/02/28 12:53:53 wiz Exp $
#

DISTNAME=	libdnet-1.10
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "alpha"
CONFIGURE_ARGS+=	--without-check
.endif

.include "../../mk/bsd.pkg.mk"
