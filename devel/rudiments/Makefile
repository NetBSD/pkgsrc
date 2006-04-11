# $NetBSD: Makefile,v 1.13 2006/04/11 12:59:33 joerg Exp $
#

DISTNAME=		rudiments-0.29
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rudiments/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rudiments.sourceforge.net/
COMMENT=		C++ class library for client/server/daemon applications

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
