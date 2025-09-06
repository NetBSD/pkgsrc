# $NetBSD: Makefile,v 1.6 2025/09/06 13:17:13 bsiegert Exp $

DISTNAME=		ov-0.43.0
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=noborus/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/noborus/ov/
COMMENT=		Feature-rich terminal-based text viewer
LICENSE=		mit

WRKSRC=			${WRKDIR}

.include "go-modules.mk"

GO_BUILD_PATTERN=	-ldflags "-X main.Version=${PKGVERSION_NOREV}" ./...

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
