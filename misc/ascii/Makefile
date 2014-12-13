# $NetBSD: Makefile,v 1.14 2014/12/13 01:05:44 mef Exp $
#

DISTNAME=	ascii-3.14
CATEGORIES=	misc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/ascii/
COMMENT=	ASCII character table program
LICENSE=	modified-bsd

USE_TOOLS=		gmake
USE_LIBTOOL=		yes

BUILD_TARGET= 		ascii
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ascii.cgi ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
