# $NetBSD: Makefile,v 1.21 2024/06/01 14:03:00 bsiegert Exp $

PKGNAME=	gopass-1.15.5
PKGREVISION=	12
DISTNAME=	gopass-${GITHUB_TAG}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=gopasspw/}
GITHUB_PROJECT=	gopass
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gopass.pw/
COMMENT=	Rewrite of the pass password manager in Go
LICENSE=	mit

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN=	.
CHECK_RELRO_SKIP+=	bin/gopass

INSTALLATION_DIRS+=	bin \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

do-build:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}

post-build:
	cd ${WRKDIR}/.gopath && \
	./bin/gopass completion bash > ${WRKSRC}/completion.bash && \
	./bin/gopass completion fish > ${WRKSRC}/completion.fish && \
	./bin/gopass completion zsh  > ${WRKSRC}/completion.zsh

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/completion.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/gopass
	${INSTALL_DATA} ${WRKSRC}/completion.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/gopass.fish
	${INSTALL_DATA} ${WRKSRC}/completion.zsh \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_gopass

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
