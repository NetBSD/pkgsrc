# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:02 rillig Exp $
#

DISTNAME=	aegis-4.15
CATEGORIES=	devel
MASTER_SITES=	http://aegis.sourceforge.net/

MAINTAINER=	Matthew@Aldous.com
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Aegis is a transaction base software configuration management system

GNU_CONFIGURE=	YES
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--with-nlsdir=${_PKGLOCALEDIR:Q}

.include "../../mk/bsd.pkg.mk"
