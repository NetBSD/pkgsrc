# $NetBSD: Makefile,v 1.11 2024/06/01 14:03:01 bsiegert Exp $

DISTNAME=	autorestic-1.8.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cupcakearmy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cupcakearmy/autorestic/
COMMENT=	Config driven, easy backup CLI for restic
LICENSE=	apache-2.0

USE_LANGUAGES=	c

.include "go-modules.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/build

# Generate shell completion scripts unless we are cross-compiling the
# package. Not sure if Go supports cross-compilation though.
PLIST_VARS+=	comp
.include "../../lang/go/go-vars.mk"
.include "../../mk/bsd.prefs.mk"
.if ${USE_CROSS_COMPILE:U:tl} != "yes"
COMP.shell-types=	bash fish zsh
COMP.script.bash=	share/bash-completion/completions/autorestic
COMP.script.fish=	share/fish/completions/autorestic.fish
COMP.script.zsh=	share/zsh/site-functions/_autorestic

.  for sh in ${COMP.shell-types}
INSTALLATION_DIRS+=	${COMP.script.${sh}:H}
PRINT_PLIST_AWK+=	/^${COMP.script.${sh}:S,/,\\/,g}/ \
				{ $$0 = "$${PLIST.comp}" $$0 }
.  endfor
PLIST.comp=		YES

post-install: install-completion-scripts
.PHONY: install-completion-scripts
install-completion-scripts:
	@${STEP_MSG} "Generating shell completion scripts for ${PKGNAME}"
.  for sh in ${COMP.shell-types}
	${DESTDIR}${PREFIX}/bin/autorestic completion ${sh} \
		> ${DESTDIR}${PREFIX}/${COMP.script.${sh}}
.  endfor
.endif

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
