# $NetBSD: Makefile,v 1.3 2003/10/11 13:40:19 grant Exp $
#

DISTNAME=		expatobjc-1.0
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=expatobjc/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://expatobjc.sourceforge.net/
COMMENT=		Objective-C Wrapper for Expat

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		objc_works=yes

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
