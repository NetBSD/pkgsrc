# $NetBSD: Makefile,v 1.2 2024/12/08 08:26:13 iquiw Exp $

PKGNAME=	task-3.40.1

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

# go module checksum calcuated from the extracted source.
TASK_GO_SUM=		h1:Q/TjPh5SAI+XK2fBravDPZXNGm6mvnwrLJqCXfhZ3Wc=

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/go-task/task/v3/internal/version.version=${GITHUB_TAG} \
			-X github.com/go-task/task/v3/internal/version.sum=${TASK_GO_SUM}'
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
