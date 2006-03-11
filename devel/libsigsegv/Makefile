# $NetBSD: Makefile,v 1.1.1.1 2006/03/11 22:00:01 wiz Exp $
#

DISTNAME=		libsigsegv-2.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libsigsegv/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://libsigsegv.sourceforge.net/
COMMENT=		Library for handling page faults in user mode

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
