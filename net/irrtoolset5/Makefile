# $NetBSD: Makefile,v 1.2 2010/01/31 21:49:16 spz Exp $
#

DISTNAME=		irrtoolset-5.0.0pre311
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}
PKGREVISION=		1

OWNER=			spz@NetBSD.org
HOMEPAGE=		http://irrtoolset.isc.org/
COMMENT=		The Internet Routing Registry Toolset - client to IRRd
LICENSE=		no-commercial-use

CONFLICTS=		IRRToolSet-4.*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${PKGBINDIR} ${PKGMANDIR}/man1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=             bison flex
GCC_REQD+=		3.0

CONFIG_GUESS_OVERRIDE=	config.guess
CONFIG_SUB_OVERRIDE=	config.sub

.if !empty(MACHINE_PLATFORM:MNetBSD-[1-4].*) || !empty(MACHINE_PLATFORM:MNetBSD-5\.[0-9][\._]*)
CONFIGURE_ENV+=		LEX="${PREFIX}/bin/flex"
.include "../../devel/flex/buildlink3.mk"
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
