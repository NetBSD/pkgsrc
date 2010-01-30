# $NetBSD: Makefile,v 1.1.1.1 2010/01/30 16:14:16 spz Exp $
#

DISTNAME=		irrtoolset-5.0.0pre311
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

OWNER=			spz@NetBSD.org
HOMEPAGE=		http://irrtoolset.isc.org/
COMMENT=		The Internet Routing Registry Toolset - client to IRRd
LICENSE=		no-commercial-use

CONFLICTS=		IRRToolSet-4.*

INSTALLATION_DIRS=	${PKGBINDIR} ${PKGMANDIR}/man1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=             bison flex
GCC_REQD+=		3.0

CONFIG_GUESS_OVERRIDE=	config.guess
CONFIG_SUB_OVERRIDE=	config.sub

PKG_DESTDIR_SUPPORT=user-destdir

.include "../../mk/bsd.pkg.mk"
