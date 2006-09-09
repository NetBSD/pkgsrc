# $NetBSD: Makefile,v 1.15 2006/09/09 02:43:09 obache Exp $

DISTNAME=	cwtext-0.95
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cwtext/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cwtext.sourceforge.net/
COMMENT=	Morse Code Generator

MAKE_FILE=	makefile
USE_TOOLS+=	gmake
BUILD_TARGET=	ALL

INSTALLATION_DIRS=	bin

post-patch:
	${SED} 	-e "s,^PREFIX,#PREFIX,g"	\
		-e "s,gcc,${CC} ${CFLAGS},g"	\
		-e "s,python,${PYTHONBIN},g"	\
		${WRKSRC}/${MAKE_FILE} > ${WRKSRC}/${MAKE_FILE}.done
	${MV} ${WRKSRC}/${MAKE_FILE}.done ${WRKSRC}/${MAKE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cwpcm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cwtext ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cwmm ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
