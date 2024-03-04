# $NetBSD: Makefile,v 1.4 2024/03/04 13:05:28 wiz Exp $

DISTNAME=	0.17.0
PKGNAME=	aerc-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	https://git.sr.ht/~rjarry/aerc/archive/
DIST_SUBDIR=	aerc

MAINTAINER=	ktnb@posteo.net
HOMEPAGE=	https://git.sr.ht/~rjarry/aerc/
COMMENT=	Terminal email client written in Go
LICENSE=	mit

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake
USE_LANGUAGES=	c

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}
MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

REPLACE_PYTHON+=	contrib/carddav-query
REPLACE_PYTHON+=	filters/show-ics-details.py

GO_BUILD_PATTERN=	.

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV}	\
	    GOPATH=${WRKDIR}/.gopath ${GO} build -o aerc

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_MAKE_FLAGS} install

.include "go-modules.mk"

.include "../../lang/python/application.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
