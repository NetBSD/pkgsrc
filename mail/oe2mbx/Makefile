# $NetBSD: Makefile,v 1.1.1.1 2001/06/04 11:34:03 zuntum Exp $
#

DISTNAME=	oe2mbx-1.21
CATEGORIES=	mail
MASTER_SITES=	http://www.gpl.no/liboe/download/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.gpl.no/liboe/
COMMENT=	Outlook Express messages to the Unix mailbox format converter

MAKEFILE=	makefile

ALL_TARGET=	liboe oe2mbx

WRKSRC=		${WRKDIR}/liboe-0.92

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

post-patch:
	${SED}	-e "s,gcc,${CC} ${CFLAGS},g"				\
		-e "s,^PREFIX,#PREFIX,g"				\
		 ${WRKSRC}/${MAKEFILE} > ${WRKSRC}/${MAKEFILE}.done
	${MV} ${WRKSRC}/${MAKEFILE}.done ${WRKSRC}/${MAKEFILE}

.include "../../mk/bsd.pkg.mk"
