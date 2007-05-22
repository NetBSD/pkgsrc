# $NetBSD: Makefile,v 1.10 2007/05/22 12:18:23 spz Exp $
#

DISTNAME=		IRRToolSet-4.8.5
PKGREVISION=	0
CATEGORIES=		net
MASTER_SITES=	ftp://ftp.isc.org/isc/IRRToolSet/IRRToolSet-4.8.5/

MAINTAINER=		spz@NetBSD.org
HOMEPAGE=		http://www.isc.org/index.pl?/sw/IRRToolSet/
COMMENT=		The Internet Routing Registry Toolset - client to IRRd

USE_LANGUAGES=		c c++
USE_TOOLS+=         perl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

LICENSE=		no-commercial-use

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-x

CONFIG_GUESS_OVERRIDE=	config.guess src/Core/.aux/config.guess \
	src/rpsl/config.guess
CONFIG_SUB_OVERRIDE=	config.sub src/Core/.aux/config.sub \
	src/rpsl/config.sub

.include "../../mk/bsd.pkg.mk"
