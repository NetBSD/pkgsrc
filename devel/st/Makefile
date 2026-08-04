# $NetBSD: Makefile,v 1.24 2026/08/04 20:28:52 wiz Exp $
#

DISTNAME=	st-1.9
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=state-threads/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://state-threads.sourceforge.net/
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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
