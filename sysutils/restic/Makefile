# $NetBSD: Makefile,v 1.74 2026/05/07 18:50:08 bsiegert Exp $

DISTNAME=	restic-0.18.1
PKGREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=restic/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://restic.net/
COMMENT=	Fast, secure, efficient backup program
LICENSE=	2-clause-bsd

EXTRACT_USING=	bsdtar

GO_BUILD_PATTERN=	./cmd/restic

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 \
			share/bash-completion/completions \
			share/fish/completions \
			share/zsh/site-functions

.include "go-modules.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/bash-completion.sh \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/restic
	${INSTALL_DATA} ${WRKSRC}/doc/fish-completion.fish \
			${DESTDIR}${PREFIX}/share/fish/completions/restic.fish
	${INSTALL_DATA} ${WRKSRC}/doc/zsh-completion.zsh \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_restic
	for man in ${WRKSRC}/doc/man/restic*.1; do \
		${INSTALL_MAN} $${man} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
