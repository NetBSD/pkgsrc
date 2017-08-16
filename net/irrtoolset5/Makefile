# $NetBSD: Makefile,v 1.10 2017/08/16 20:45:42 wiz Exp $

VERSION=		5.0.1
DISTNAME=		irrtoolset-${VERSION}
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.isc.org/isc/IRRToolSet/IRRToolSet-${VERSION}/

OWNER=			spz@NetBSD.org
#HOMEPAGE=		http://irrtoolset.isc.org/
COMMENT=		The Internet Routing Registry Toolset - client to IRRd
LICENSE=		gnu-gpl-v2 AND mit AND modified-bsd

CONFLICTS=		IRRToolSet-4.*

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${PKGBINDIR} ${PKGMANDIR}/man1

MAKE_JOBS_SAFE=		NO

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex
GCC_REQD+=		3.0

CONFIG_GUESS_OVERRIDE=	config.guess
CONFIG_SUB_OVERRIDE=	config.sub

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		LEX="${PREFIX}/bin/flex"
.include "../../devel/flex/buildlink3.mk"
.endif

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
