# $NetBSD: Makefile,v 1.3 2004/04/12 02:03:11 snj Exp $
#

DISTNAME=	aegis-4.15
CATEGORIES=	devel
MASTER_SITES=	http://aegis.sourceforge.net/

MAINTAINER=	Matthew@Aldous.com
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Aegis is a transaction base software configuration management system

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS=		--with-nlsdir=${_PKGLOCALEDIR}

.include "../../mk/bsd.pkg.mk"
