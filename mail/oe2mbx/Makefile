# $NetBSD: Makefile,v 1.5 2004/12/03 15:15:02 wiz Exp $
#

DISTNAME=	oe2mbx-1.21
CATEGORIES=	mail
MASTER_SITES=	http://www.gpl.no/liboe/download/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.gpl.no/liboe/
COMMENT=	Outlook Express messages to the Unix mailbox format converter

WRKSRC=		${WRKDIR}/liboe-0.92
MAKEFILE=	makefile

BUILD_TARGET=	liboe oe2mbx

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

post-patch:
	${SED}	-e "s,gcc,${CC} ${CFLAGS},g"				\
		-e "s,^PREFIX,#PREFIX,g"				\
		 ${WRKSRC}/${MAKEFILE} > ${WRKSRC}/${MAKEFILE}.done
	${MV} ${WRKSRC}/${MAKEFILE}.done ${WRKSRC}/${MAKEFILE}

.include "../../mk/bsd.pkg.mk"
