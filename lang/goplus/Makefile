# $NetBSD: Makefile,v 1.6 2024/06/01 14:02:54 bsiegert Exp $

DISTNAME=	goplus-1.2.6
MASTER_SITES=	${MASTER_SITE_GITHUB:=goplus/}
PKGREVISION=	1
CATEGORIES=	lang
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	gop

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://goplus.org/
COMMENT=	The Go+ programming language
LICENSE=	apache-2.0

USE_TOOLS+=	bash:run pax

GOPROOT_FINAL=		${PREFIX}/gop
INSTALLATION_DIRS=	bin gop

REPLACE_BASH+=	all.bash
REPLACE_BASH+=	make.bash

.include "go-modules.mk"

do-install:
	${MKDIR} ${DESTDIR}${GOPROOT_FINAL}/bin
.for cmd in gop gopfmt goptestgo
	${INSTALL} ${WRKDIR}/.gopath/bin/${cmd} ${DESTDIR}${GOPROOT_FINAL}/bin/${cmd}
	${LN} -sf ${DESTDIR}${GOPROOT_FINAL}/bin/${cmd} ${DESTDIR}${PREFIX}/bin/${cmd}
.endfor
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/gop
.for i in .github .gitattributes .gitignore .goreleaser.yaml Makefile \
	Dockerfile CODE_OF_CONDUCT.md LICENSE README.md VERSION _gendeps.go \
	all.bash all.bat build_install_run.go gengo.go imp.go load.go make.bash \
	make.bat outline.go tidy.go
	${RM} -rf ${DESTDIR}${PREFIX}/gop/${i}
.endfor

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
