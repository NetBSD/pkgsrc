# $NetBSD: Makefile,v 1.34 2007/08/12 13:17:12 joerg Exp $

DISTNAME=	glimpse-4.18.0
PKGREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://webglimpse.net/trial/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	glimpse-license
RESTRICTED=	Restrictive copyright (don't sell for profit)
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	yes
MAKE_FLAGS=	mandir=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	share/doc/glimpse

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
