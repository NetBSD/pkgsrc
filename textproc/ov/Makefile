# $NetBSD: Makefile,v 1.16 2026/02/22 11:04:06 wiz Exp $

DISTNAME=		ov-0.51.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=noborus/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://noborus.github.io/ov/
COMMENT=		Feature-rich terminal-based text viewer
LICENSE=		mit

WRKSRC=			${WRKDIR}

.include "go-modules.mk"

GOFLAGS=		-ldflags "-X main.Version=${PKGVERSION_NOREV}"
GO_BUILD_PATTERN=	./...

AUTO_MKDIRS=		yes

post-extract:
	cd ${WRKSRC} && ${RM} -rf examples/

post-install:
	cd ${WRKSRC} && for f in *.yaml; do \
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/; \
	done; \
	${INSTALL_DATA} README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/
	${DESTDIR}${PREFIX}/bin/ov --completion bash > \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/${PKGBASE}
	${DESTDIR}${PREFIX}/bin/ov --completion fish > \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/${PKGBASE}.fish
	${DESTDIR}${PREFIX}/bin/ov --completion zsh > \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_${PKGBASE}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
