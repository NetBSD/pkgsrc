# $NetBSD: Makefile,v 1.1.1.1 2003/07/19 08:19:14 rh Exp $
#

DISTNAME=		expatobjc-1.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=expatobjc/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://expatobjc.sourceforge.net/
COMMENT=		Objective-C Wrapper for Expat

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
