# $NetBSD: Makefile,v 1.5 2004/11/26 22:51:50 wiz Exp $
#

DISTNAME=	libdnet-1.7
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.pkg.mk"
