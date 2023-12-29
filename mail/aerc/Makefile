# $NetBSD: Makefile,v 1.1 2023/12/29 20:58:14 wiz Exp $

DISTNAME=	0.16.0
PKGNAME=	aerc-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	https://git.sr.ht/~rjarry/aerc/archive/
DIST_SUBDIR=	aerc

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://git.sr.ht/~rjarry/aerc/archive/
COMMENT=	Terminal email client written in Go
LICENSE=	mit

TOOL_DEPENDS+=	go118>=1.18.0:../../lang/go118
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

WRKSRC=		${WRKDIR}/aerc-0.16.0

USE_TOOLS+=	gmake
#MAKE_FILE=	GNUmakefile
USE_LANGUAGES=	c

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}
MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

REPLACE_PYTHON+=	contrib/carddav-query
REPLACE_PYTHON+=	filters/show-ics-details.py
.include "../../lang/python/application.mk"

GO_BUILD_PATTERN=	.

#pre-build:
#	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV}	\
#	    GOPATH=${WRKDIR}/.gopath ${GO} generate ./...

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV}	\
	    GOPATH=${WRKDIR}/.gopath ${GO} build -o aerc

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_MAKE_FLAGS} install

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
