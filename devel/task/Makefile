# $NetBSD: Makefile,v 1.25 2026/04/26 09:24:49 iquiw Exp $

PKGNAME=	task-3.50.0

DISTNAME=	task-${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-task/}
GITHUB_PROJECT=	task
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://taskfile.dev/
COMMENT=	Task-runner / simpler Make alternative written in Go
LICENSE=	mit

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN+=	./cmd/task

INSTALLATION_DIRS+=	bin \
			share/bash-completion/completions \
			share/zsh/site-functions

do-install:
	${RUN} cd ${WRKDIR}/.gopath && [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${INSTALL_DATA} ${WRKSRC}/completion/bash/task.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/task
	${INSTALL_DATA} ${WRKSRC}/completion/zsh/_task \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_task

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
