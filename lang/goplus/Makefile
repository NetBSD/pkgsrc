# $NetBSD: Makefile,v 1.2 2023/04/19 13:19:51 nikita Exp $

DISTNAME=	goplus-1.1.3
MASTER_SITES=	${MASTER_SITE_GITHUB:=goplus/}
CATEGORIES=	lang
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	gop

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://goplus.org/
COMMENT=	The Go+ programming language
LICENSE=	apache-2.0

USE_TOOLS+=	bash:run
# https://github.com/goplus/gop/issues/1350
DEPENDS+=	go120-[0-9]*:../../lang/go119

# cgo compiles under TMPDIR
.include "../../mk/bsd.prefs.mk"
TMPDIR?=	/tmp
BUILDLINK_PASSTHRU_DIRS+= ${TMPDIR}

INSTALLATION_DIRS=	bin

REPLACE_BASH+=	all.bash
REPLACE_BASH+=	make.bash

.include "go-modules.mk"

do-install:
.for cmd in gop gopdecl gopfmt goptestgo
	${INSTALL} ${WRKDIR}/.gopath/bin/${cmd} ${DESTDIR}${PREFIX}/bin/${cmd}
.endfor

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
