# $NetBSD: Makefile,v 1.5 2002/04/10 17:05:37 agc Exp $

DISTNAME=	onyx-${VERS}
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.canonware.com/
COMMENT=	Embeddable stack-based threaded interpreted language

# needs EL_CLIENTDATA in /usr/include/histedit.h
ONLY_FOR_PLATFORM=	NetBSD-1.5[YZ]*-* NetBSD-1.6-*

BUILD_DEPENDS=	cook-[0-9]*:../../devel/cook

GNU_CONFIGURE=	yes
# XXX
CONFIGURE_ARGS+= --disable-threads

VERS=		3.0.2
PLIST_SUBST+=	VERS=${VERS}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook install)

post-install:
	@strip ${PREFIX}/bin/onyx

.include "../../mk/bsd.pkg.mk"
