# $NetBSD: Makefile,v 1.2 2002/04/03 18:02:07 wiz Exp $

DISTNAME=	onyx-${VERS}
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.canonware.com/
COMMENT=	Embeddable stack-based threaded interpreted language

BUILD_DEPENDS=	cook-*:../../devel/cook

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
