# $NetBSD: Makefile,v 1.6 2021/08/10 19:24:22 prlw1 Exp $

DISTNAME=	asio-1.19.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://think-async.com/
COMMENT=	Header-only C++ library for asynchronous programming
LICENSE=	boost-license

USE_LANGUAGES=	# none
USE_TOOLS=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	include

do-install:
	cd ${WRKSRC} && \
	${FIND} include -name "*.*pp" | ${PAX} -r -w  ${DESTDIR}${PREFIX}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
