# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:57 jlam Exp $
#

DISTNAME=		openrm-devel-1.5.2
PKGNAME=		OpenRM-1.5.2
PKGREVISION=	1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openrm/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.openrm.org/
COMMENT=		The OpenRM Scene Graph API

WRKSRC=			${WRKDIR}/rm152
BUILD_TARGET=		freebsd docs
MAKE_ENV+=		AR=${AR} RM=${RM} CP=${CP} LN=${LN} ECHO_CMD=${ECHO} \
			STRIP_CMD=${ECHO}

INSTALLATION_DIRS=	lib

post-patch:
	${MV} ${WRKSRC}/doc/sortlist.pl ${WRKSRC}/doc/sortlist.pl.orig && \
		${SED} -e 's|%%PERLBIN%%|${PERL5}|g'			  \
		${WRKSRC}/doc/sortlist.pl.orig > ${WRKSRC}/doc/sortlist.pl
	${CHMOD} 755 ${WRKSRC}/doc/sortlist.pl
	${MV} ${WRKSRC}/doc/source2html.pl ${WRKSRC}/doc/source2html.pl.orig &&\
		${SED} -e 's|%%PERLBIN%%|${PERL5}|g'			  \
		${WRKSRC}/doc/source2html.pl.orig > ${WRKSRC}/doc/source2html.pl
	${CHMOD} 755 ${WRKSRC}/doc/source2html.pl

do-install:
# install libraries
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librm.so.1 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librmaux.so.1 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librmi.so.1 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librmv.so.1 ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/librm.so.1 ${PREFIX}/lib/librm.so
	${LN} -fs ${PREFIX}/lib/librmaux.so.1 ${PREFIX}/lib/librmaux.so
	${LN} -fs ${PREFIX}/lib/librmi.so.1 ${PREFIX}/lib/librmi.so
	${LN} -fs ${PREFIX}/lib/librmv.so.1 ${PREFIX}/lib/librmv.so
	${INSTALL_DATA} ${WRKSRC}/lib/librm.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/librmaux.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/librmi.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/librmv.a ${PREFIX}/lib
# install includes
	${INSTALL_DATA_DIR} ${PREFIX}/include/rm
	${INSTALL_DATA} ${WRKSRC}/include/rm/*.h ${PREFIX}/include/rm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/OpenRM
	${INSTALL_DATA} ${WRKSRC}/FUTUREPLANS ${PREFIX}/share/doc/OpenRM
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/OpenRM
	${INSTALL_DATA} ${WRKSRC}/RELEASENOTES ${PREFIX}/share/doc/OpenRM
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/*.html ${PREFIX}/share/doc/OpenRM
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/OpenRM/images
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/images/* ${PREFIX}/share/doc/OpenRM/images

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
