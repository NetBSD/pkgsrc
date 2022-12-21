# $NetBSD: Makefile,v 1.2 2022/12/21 13:13:36 wiz Exp $

DISTNAME=	jpm-1.1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=janet-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
