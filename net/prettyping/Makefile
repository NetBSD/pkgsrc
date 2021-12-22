# $NetBSD: Makefile,v 1.1 2021/12/22 16:16:29 schmonz Exp $

GITHUB_TAG=		refs/tags/v${PKGVERSION_NOREV}
DISTNAME=		prettyping-1.0.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=denilsonsa/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/denilsonsa/prettyping/
COMMENT=		Wrapper to colorize and simplify ping's output
LICENSE=		mit

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		# none
NO_BUILD=		yes

USE_TOOLS+=		bash:run
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/usr/bin/env bash
REPLACE.bash.new=	${BASH}
REPLACE_FILES.bash=	${PKGBASE}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
