# $NetBSD: Makefile,v 1.14 2004/10/03 00:15:02 tv Exp $

DISTNAME=	onyx-${VERS}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.canonware.com/onyx/
COMMENT=	Embeddable stack-based threaded interpreted language

BUILD_DEPENDS+=	cook-[0-9]*:../../devel/cook

# needs EL_CLIENTDATA in /usr/include/histedit.h
ONLY_FOR_PLATFORM=	NetBSD-1.5[YZ]*-* NetBSD-1.6*-* NetBSD-1.7*-* NetBSD-[2-9]*

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-pcre-prefix=${BUILDLINK_PREFIX.pcre}

BUILDLINK_DEPENDS.pcre?=        pcre>=4.0

VERS=		5.1.1
PLIST_SUBST+=	VERS=${VERS}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook install)

post-install:
	@strip ${PREFIX}/bin/onyx

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
