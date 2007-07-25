# $NetBSD: Makefile,v 1.2 2007/07/25 00:19:33 rillig Exp $
#

DISTNAME=	veleng10
PKGNAME=	velena-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.ce.unipr.it/~gbe/
EXTRACT_SUFX=	.zip

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.ce.unipr.it/~gbe/
COMMENT=	Perfect-play engine for connect four

LICENSE=		public-domain
RESTRICTED=		You must not charge a fee for this software nor for any derived work in which this software is included.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

EXTRACT_OPTS_ZIP=	-LLaqo
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
INSTALLATION_DIRS_FROM_PLIST=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/veleng ${DESTDIR}${PREFIX}/bin/velena
	${INSTALL_DATA} ${WRKSRC}/readme ${DESTDIR}${PREFIX}/share/doc/velena/README

.include "../../mk/bsd.pkg.mk"
