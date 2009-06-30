# $NetBSD: Makefile,v 1.38 2009/06/30 00:07:23 joerg Exp $

DISTNAME=	glimpse-4.18.5
CATEGORIES=	textproc databases
MASTER_SITES=	http://webglimpse.net/trial/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine
LICENSE=	glimpse-license

RESTRICTED=	Redistribution only on non-profit basis.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	yes
MAKE_FLAGS=	mandir=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	share/doc/glimpse

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
