# $NetBSD: Makefile,v 1.4 2004/01/20 12:19:43 agc Exp $
#

DISTNAME=	oe2mbx-1.21
CATEGORIES=	mail
MASTER_SITES=	http://www.gpl.no/liboe/download/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.gpl.no/liboe/
COMMENT=	Outlook Express messages to the Unix mailbox format converter

WRKSRC=		${WRKDIR}/liboe-0.92
MAKEFILE=	makefile

ALL_TARGET=	liboe oe2mbx

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

post-patch:
	${SED}	-e "s,gcc,${CC} ${CFLAGS},g"				\
		-e "s,^PREFIX,#PREFIX,g"				\
		 ${WRKSRC}/${MAKEFILE} > ${WRKSRC}/${MAKEFILE}.done
	${MV} ${WRKSRC}/${MAKEFILE}.done ${WRKSRC}/${MAKEFILE}

.include "../../mk/bsd.pkg.mk"
