# $NetBSD: Makefile,v 1.3 2023/01/13 22:18:11 schmonz Exp $

DISTNAME=		asdf-0.11.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=asdf-vm/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://asdf-vm.com/
COMMENT=		Manage each of your project runtimes with a single tool
LICENSE=		mit

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run
NO_BUILD=		yes
REPLACE_BASH=		bin/asdf

AUTO_MKDIRS=		yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_FILES.prefix=	lib/utils.bash lib/commands/reshim.bash
SUBST_VARS.prefix=	PREFIX BASH

SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	do-configure
SUBST_FILES.lib=	bin/asdf lib/commands/*
SUBST_SED.lib=		-e 's|\$$(dirname "\$$(dirname "\$$0")")/lib|${PREFIX}/share/${PKGBASE}/lib|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/asdf \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/help.txt \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/version.txt \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/asdf.elv \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/asdf.fish \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/asdf.nu \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/asdf.sh \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/lib/asdf.fish \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/asdf.sh \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/utils.bash \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/commands/*.bash \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/lib/commands/
	${INSTALL_DATA} ${WRKSRC}/lib/functions/*.bash \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/lib/functions/
	${TOUCH} \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/lib/asdf_updates_disabled
	${INSTALL_DATA} ${WRKSRC}/completions/asdf.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/asdf
	${INSTALL_DATA} ${WRKSRC}/completions/asdf.fish \
		${DESTDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${WRKSRC}/completions/_asdf \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/

.include "../../mk/bsd.pkg.mk"
