# $NetBSD: Makefile,v 1.3 2004/04/20 07:56:31 xtraeme Exp $
#

DISTNAME=	libdnet-1.7
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	bit5hfit@ethernet.tk
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.pkg.mk"
