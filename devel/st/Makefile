# $NetBSD: Makefile,v 1.16 2012/12/17 01:58:55 dholland Exp $
#

DISTNAME=	st-1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=state-threads/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://state-threads.sourceforge.net/
COMMENT=	Non-preemptive thread library for Internet applications

ONLY_FOR_PLATFORM=	NetBSD-*-x86_64 NetBSD-*-i386 \
			NetBSD-*-sparc NetBSD-*-vax
MAKE_JOBS_SAFE=		no

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
BUILD_TARGET=	netbsd-debug

HTMLDIR=	${PREFIX}/share/doc/html/st

INSTALLATION_DIRS=	bin include lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/libst.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/lookupdns ${DESTDIR}${PREFIX}/bin/st-lookupdns
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/proxy ${DESTDIR}${PREFIX}/bin/st-proxy
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/server ${DESTDIR}${PREFIX}/bin/st-server
	${INSTALL_DATA} ${WRKSRC}/public.h ${DESTDIR}${PREFIX}/include/st.h
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} *.html *.gif ${DESTDIR}${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
