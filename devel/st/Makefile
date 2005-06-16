# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:48 jlam Exp $
#

DISTNAME=	st-1.5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=state-threads/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://state-threads.sourceforge.net/
COMMENT=	Non-preemptive thread library for Internet applications

ONLY_FOR_PLATFORM=     NetBSD-*-i386 NetBSD-*-sparc NetBSD-*-vax

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
BUILD_TARGET=	netbsd-debug

HTMLDIR=	${PREFIX}/share/doc/html/st

INSTALLATION_DIRS=	bin lib

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
