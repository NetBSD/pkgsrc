# $NetBSD: Makefile,v 1.1.1.1 2001/03/20 11:57:41 wiz Exp $
#

DISTNAME=	maude-linux
PKGNAME=	maude-1.0.5
CATEGORIES=	lang
MASTER_SITES=	http://maude.csl.sri.com/system/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://maude.csl.sri.com/
COMMENT=	system for equational and rewriting logic specification/programming

# see http://maude.csl.sri.com/license/license.html
#LICENSE=	maude-license

RESTRICTED=		license does not explicitly allow redistribution
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NO_PATCH=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/maude-linux/bin/maude.linux ${PREFIX}/bin/maude
	${INSTALL_SCRIPT} ${WRKDIR}/maude-linux/bin/full-maude.maude ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/maude-linux/bin/prelude.maude ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/maude
	${INSTALL_DATA} ${WRKDIR}/maude-linux/examples/* ${PREFIX}/share/examples/maude

.include "../../mk/bsd.pkg.mk"
