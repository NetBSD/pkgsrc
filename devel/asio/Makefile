# $NetBSD: Makefile,v 1.9 2026/07/07 07:02:32 prlw1 Exp $

DISTNAME=	asio-1.36.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://think-async.com/
COMMENT=	Header-only C++ library for asynchronous programming
LICENSE=	boost-license

USE_LANGUAGES=	# none
USE_TOOLS=	pax tar
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	include

do-extract:
	cd ${WRKDIR} && \
	${TAR} -xzf "${DISTDIR}/${DISTFILES}" '*/include/*.*pp'

do-install:
	cd ${WRKSRC} && \
	${PAX} -r -w include ${DESTDIR}${PREFIX}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
