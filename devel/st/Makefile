# $NetBSD: Makefile,v 1.22 2020/03/20 11:57:32 nia Exp $
#

DISTNAME=	st-1.9
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=state-threads/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://state-threads.sourceforge.net/
COMMENT=	Non-preemptive thread library for Internet applications
LICENSE=	mpl-1.1

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_ENV+=	CONFIG_GUESS_PATH=.
BUILD_TARGET=	default
AUTO_MKDIRS=	yes

post-extract:
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/target/libst.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/lookupdns ${DESTDIR}${PREFIX}/bin/st-lookupdns
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/proxy ${DESTDIR}${PREFIX}/bin/st-proxy
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/examples/server ${DESTDIR}${PREFIX}/bin/st-server
	${INSTALL_DATA} ${WRKSRC}/public.h ${DESTDIR}${PREFIX}/include/st.h
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html *.gif \
		${DESTDIR}${PREFIX}/share/doc/st

.include "../../mk/bsd.pkg.mk"
