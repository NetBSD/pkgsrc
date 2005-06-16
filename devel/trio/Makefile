# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:48 jlam Exp $
#

DISTNAME=	trio-1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.contactor.se/~dast/stuff/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.contactor.se/~dast/trio/
COMMENT=	Fully matured and stable set of printf and string functions

INSTALLATION_DIRS=	include lib man/man3

post-patch:
	${SED} "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile			\
		> ${WRKSRC}/Makefile.done
	${MV} ${WRKSRC}/Makefile.done ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC} &&							\
		${INSTALL_DATA}	trio.h triop.h ${PREFIX}/include
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} libtrio.a ${PREFIX}/lib
	cd ${WRKSRC}/man/man3 &&					\
		${INSTALL_MAN} trio_printf.3 trio_scanf.3		\
		trio_register.3 strio.3 ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
