# $NetBSD: Makefile,v 1.1.1.1 2005/02/28 12:37:29 spz Exp $
#

DISTNAME=		IRRToolSet-4.8.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.isc.org/isc/IRRToolSet/IRRToolSet-4.8.2/

MAINTAINER=		spz@NetBSD.org
HOMEPAGE=		http://www.isc.org/index.pl?/sw/IRRToolSet/
COMMENT=		The Internet Routing Registry Toolset - client to IRRd

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=        --without-x

.include "../../mk/bsd.pkg.mk"
