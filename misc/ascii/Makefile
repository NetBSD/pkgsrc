# $NetBSD: Makefile,v 1.12 2008/06/19 17:33:50 bjs Exp $
#

DISTNAME=	ascii-3.8
CATEGORIES=	misc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/ascii/
COMMENT=	ASCII character table program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS=		gmake
USE_LIBTOOL=		yes

BUILD_TARGET= 		ascii
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ascii.cgi ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
