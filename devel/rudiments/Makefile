# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:33 tv Exp $
#

DISTNAME=		rudiments-0.25.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rudiments/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rudiments.sourceforge.net/
COMMENT=		C++ class library for client/server/daemon applications

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
