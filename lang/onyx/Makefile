# $NetBSD: Makefile,v 1.26 2012/10/02 20:11:46 asau Exp $

DISTNAME=	onyx-${VERS}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.canonware.com/onyx/
COMMENT=	Embeddable stack-based threaded interpreted language

BUILD_DEPENDS+=	cook-[0-9]*:../../devel/cook

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-pcre-prefix=${BUILDLINK_PREFIX.pcre}

BUILDLINK_API_DEPENDS.pcre?=        pcre>=4.0

VERS=		5.1.2
PLIST_SUBST+=	VERS=${VERS:Q}

MAKE_ENV+=	SHELL=/bin/sh

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} cook

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} cook install

post-install:
	strip ${DESTDIR}${PREFIX}/bin/onyx

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "pth"
.include "../../devel/pthread-sem/buildlink3.mk"
LIBS+=		-lsemaphore
.endif

.include "../../mk/bsd.pkg.mk"
