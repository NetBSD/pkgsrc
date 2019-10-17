# $NetBSD: Makefile,v 1.11 2019/10/17 14:05:49 he Exp $

VERSION=		5.1.2
DISTNAME=		irrtoolset-${VERSION}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=irrtoolset/}

OWNER=			spz@NetBSD.org
HOMEPAGE=		https://github.com/irrtoolset/irrtoolset/
COMMENT=		The Internet Routing Registry Toolset - client to IRRd
GITHUB_TAG=		release-${VERSION}
LICENSE=		gnu-gpl-v2 AND mit AND modified-bsd

CONFLICTS=		IRRToolSet-4.*

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${PKGBINDIR} ${PKGMANDIR}/man1

MAKE_JOBS_SAFE=		NO

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		aclocal automake autoconf bison flex

CONFIG_GUESS_OVERRIDE=	config.guess
CONFIG_SUB_OVERRIDE=	config.sub

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoreconf --install
	cd ${WRKSRC} && automake --add-missing
	cd ${WRKSRC} && autoconf -v -i -f

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
