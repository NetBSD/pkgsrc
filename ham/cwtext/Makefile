# $NetBSD: Makefile,v 1.2 2002/04/19 15:19:07 zuntum Exp $

DISTNAME=	cwtext-0.91
CATEGORIES=	ham
MASTER_SITES=	http://prdownloads.sourceforge.net/cwtext/

MAINTAINER=	packages@netbsd.org
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

.include "../../lang/python/application.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
