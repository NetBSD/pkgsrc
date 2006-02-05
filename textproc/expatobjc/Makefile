# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:01 joerg Exp $
#

DISTNAME=		expatobjc-1.0
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=expatobjc/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://expatobjc.sourceforge.net/
COMMENT=		Objective-C Wrapper for Expat

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		objc_works=yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
