# $NetBSD: Makefile,v 1.11 2019/11/03 10:39:31 rillig Exp $

DISTNAME=	ucpp-1.3.2
CATEGORIES=	devel
#MASTER_SITES=	http://ucpp.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lpsantil/ucpp
COMMENT=	C preprocessor and lexer
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/${PKGBASE}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-DSTD_MACROS=0 -DSTD_ASSERT=0 -DNO_UCPP_BUF
SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	config.h
# remove /usr/local/include from default path
SUBST_SED.config=	-e 's|"/usr/local/include", ||'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucpp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ucpp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
