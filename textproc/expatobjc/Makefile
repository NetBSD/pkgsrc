# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:19 tv Exp $
#

DISTNAME=		expatobjc-1.0
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=expatobjc/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://expatobjc.sourceforge.net/
COMMENT=		Objective-C Wrapper for Expat

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		objc_works=yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
