# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:26 joerg Exp $
#

DISTNAME=	libdnet-1.10
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "alpha"
CONFIGURE_ARGS+=	--without-check
.endif

.include "../../mk/bsd.pkg.mk"
