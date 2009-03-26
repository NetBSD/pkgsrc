# $NetBSD: Makefile,v 1.6 2009/03/26 17:14:32 joerg Exp $
#

DISTNAME=	ucpp-1.3
CATEGORIES=	devel
MASTER_SITES=	http://ucpp.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ucpp/
COMMENT=	C preprocessor and lexer

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DSTD_MACROS=NULL -DSTD_ASSERT=NULL
MAKE_FLAGS+=	FLAGS=${CFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucpp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ucpp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
