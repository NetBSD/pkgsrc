# $NetBSD: Makefile,v 1.3 2023/01/14 07:41:00 charlotte Exp $

DISTNAME=	jpm-1.1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=janet-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/janet-lang/jpm
COMMENT=	Janet Project Manager
LICENSE=	mit

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	janet-[0-9]*:../../lang/janet

NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && DESTDIR=${DESTDIR} \
	    PREFIX=${PREFIX} \
	    JANET_MANPATH=${PREFIX}/${PKGMANDIR}/man1 \
	    ${PREFIX}/bin/janet bootstrap.janet

.include "../../mk/bsd.pkg.mk"
