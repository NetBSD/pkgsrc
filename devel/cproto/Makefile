# $NetBSD: Makefile,v 1.1.1.1 2008/10/25 06:15:38 bjs Exp $
#

.include "Makefile.version"

DISTNAME=	cproto
PKGNAME=	cproto-${CPROTO_VERSION}
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cproto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://invisible-island.net/cproto/
COMMENT=	Generates function prototypes from C source

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
###
### XXX I cannot figure out why it won't build without bash.
###	If you can fix this, please do.
###
USE_TOOLS+=	bash bison flex
CONFIG_SHELL=	${BASH}

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX:Q}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man1

.include "../../mk/bsd.pkg.mk"
