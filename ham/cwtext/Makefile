# $NetBSD: Makefile,v 1.5 2003/06/02 01:19:08 jschauma Exp $

DISTNAME=	cwtext-0.91
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cwtext/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://cwtext.sourceforge.net/
COMMENT=	Morse Code Generator

MAKEFILE=	makefile
USE_GMAKE=	YES
ALL_TARGET=	ALL

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
