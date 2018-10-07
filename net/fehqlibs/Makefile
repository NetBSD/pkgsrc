# $NetBSD: Makefile,v 1.1 2018/10/07 12:53:54 schmonz Exp $

DISTNAME=	fehQlibs-09
PKGNAME=	fehqlibs-0.9
CATEGORIES=	net
MASTER_SITES=	https://www.fehcom.de/ipnet/fehQlibs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://www.fehcom.de/ipnet/qlibs.html
COMMENT=	State-of-the-art C routines for Internet services
LICENSE=	public-domain

MAKE_JOBS_SAFE=	no

BUILD_TARGET=	libs

do-configure:
	cd ${WRKSRC};								\
	${ECHO} "LIBDIR=${DESTDIR}${PREFIX}/lib/qlibs" >> ${WRKSRC}/conf-build;	\
	${ECHO} "HDRDIR=${DESTDIR}${PREFIX}/include/qlibs" >> ${WRKSRC}/conf-build; \
	${MAKE} check

.include "../../mk/bsd.pkg.mk"
