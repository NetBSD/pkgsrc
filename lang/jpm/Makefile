# $NetBSD: Makefile,v 1.1 2021/11/04 13:52:23 nia Exp $

DISTNAME=	jpm-0.0.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=janet-lang/}

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
