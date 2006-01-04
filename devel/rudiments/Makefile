# $NetBSD: Makefile,v 1.9 2006/01/04 04:29:06 schmonz Exp $
#

DISTNAME=		rudiments-0.28.2
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
