# $NetBSD: Makefile,v 1.9 1998/09/22 06:11:40 garbled Exp $
# FreeBSD Id: Makefile,v 1.4 1997/07/15 15:00:30 cracauer Exp 
#

DISTNAME=	scsh-0.5.1
CATEGORIES=	shells lang
MASTER_SITES=	ftp://ftp-swiss.ai.mit.edu/pub/su/scsh/

NOT_FOR_ARCHS=	alpha	# Needs scheme

MAINTAINER= 	packages@netbsd.org
HOMEPAGE=	http://www-swiss.ai.mit.edu/scsh/

GNU_CONFIGURE=	yes

ALL_TARGET=	enough
MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}' \
		INSTALL_SCRIPT='${INSTALL_SCRIPT}' \
		INSTALL_DATA='${INSTALL_DATA}'

post-configure:
	cd ${WRKSRC}; ${SED} -e '/LIBGEN/d' sysdep.h >xx ; ${MV} xx sysdep.h

post-install:
	@strip ${PREFIX}/bin/scsh
	(cd ${WRKSRC} ; \
	 ${INSTALL_DATA} README RELEASE NEWS COPYING ${PREFIX}/lib/scsh/doc)
	${RM} -f ${PREFIX}/share/doc/scsh
	${LN} -fs ${PREFIX}/lib/scsh/doc ${PREFIX}/share/doc/scsh

.include "../../mk/bsd.pkg.mk"
