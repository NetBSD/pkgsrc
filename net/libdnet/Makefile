# $NetBSD: Makefile,v 1.2 2003/05/02 08:50:11 seb Exp $
#

DISTNAME=	libdnet-1.7
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	bit5hfit@ethernet.tk
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.pkg.mk"
