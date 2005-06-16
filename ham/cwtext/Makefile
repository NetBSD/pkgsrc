# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:59 jlam Exp $

DISTNAME=	cwtext-0.91
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cwtext/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cwtext.sourceforge.net/
COMMENT=	Morse Code Generator

MAKEFILE=	makefile
USE_TOOLS+=	gmake
BUILD_TARGET=	ALL

INSTALLATION_DIRS=	bin

post-patch:
	${SED} 	-e "s,^PREFIX,#PREFIX,g"	\
		-e "s,gcc,${CC} ${CFLAGS},g"	\
		-e "s,python,${PYTHONBIN},g"	\
		${WRKSRC}/${MAKEFILE} > ${WRKSRC}/${MAKEFILE}.done
	${MV} ${WRKSRC}/${MAKEFILE}.done ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cwpcm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cwtext ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
