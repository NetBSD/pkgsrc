# $NetBSD: Makefile,v 1.8 2003/11/15 08:46:15 cube Exp $
#

DISTNAME=	maude-linux
PKGNAME=	maude-1.0.5
CATEGORIES=	lang
MASTER_SITES=	http://maude.csl.sri.com/maude1/current/system/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://maude.csl.sri.com/
COMMENT=	System for equational and rewriting logic specification/programming

# see http://maude.csl.sri.com/license/license.html
LICENSE=	maude-license

RESTRICTED=		license does not explicitly allow redistribution
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

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
