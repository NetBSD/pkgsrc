# $NetBSD: Makefile,v 1.1.1.1 2002/08/25 19:40:16 gson Exp $
#

DISTNAME=	st-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=state-threads/}

MAINTAINER=	gson@netbsd.org
HOMEPAGE=	http://state-threads.sourceforge.net/
COMMENT=	Non-preemptive thread library for Internet applications

ONLY_FOR_PLATFORM=     NetBSD-*-i386 NetBSD-*-sparc

USE_LIBTOOL=	yes
USE_GMAKE=	yes
ALL_TARGET=	netbsd-debug

HTMLDIR=	${PREFIX}/share/doc/html/st

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/libst.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/lookupdns ${PREFIX}/bin/st-lookupdns
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/proxy ${PREFIX}/bin/st-proxy
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/server ${PREFIX}/bin/st-server
	${INSTALL_DATA_DIR} ${PREFIX}/include/st
	${INSTALL_DATA} ${WRKSRC}/public.h ${PREFIX}/include/st.h
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} *.html *.gif ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
