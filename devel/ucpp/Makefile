# $NetBSD: Makefile,v 1.7 2012/10/31 11:19:52 asau Exp $
#

DISTNAME=	ucpp-1.3
CATEGORIES=	devel
MASTER_SITES=	http://ucpp.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ucpp/
COMMENT=	C preprocessor and lexer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DSTD_MACROS=NULL -DSTD_ASSERT=NULL
MAKE_FLAGS+=	FLAGS=${CFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucpp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ucpp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
