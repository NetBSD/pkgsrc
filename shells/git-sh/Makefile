# $NetBSD: Makefile,v 1.1 2015/02/08 16:53:55 wiz Exp $

VERSION=	1.3
DISTNAME=	git-sh-${VERSION}
CATEGORIES=	shells
MASTER_SITES=	-https://github.com/rtomayko/git-sh/archive/${VERSION}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/git-sh/
COMMENT=	Customized bash environment suitable for git work
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run
REPLACE_BASH+=	git-sh.bash
MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/

.include "../../mk/bsd.pkg.mk"
