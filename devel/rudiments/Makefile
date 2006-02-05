# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:53 joerg Exp $
#

DISTNAME=		rudiments-0.28.2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rudiments/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rudiments.sourceforge.net/
COMMENT=		C++ class library for client/server/daemon applications

BROKEN_IN=		pkgsrc-2005Q4

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
