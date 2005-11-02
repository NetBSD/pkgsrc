# $NetBSD: Makefile,v 1.2 2005/11/02 15:32:38 tv Exp $
#

DISTNAME=	scamper-cvs-20050529
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.wand.net.nz/scamper/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://www.wand.net.nz/scamper/
COMMENT=	Dual-stack traceroute software

INSTALLATION_DIRS=bin

MAKE_FLAGS=	WITH_DEBUG=yes	# recommended by the the software developer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scamper ${PREFIX}/bin

PKG_OPTIONS_VAR=		PKG_OPTIONS.scamper
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
