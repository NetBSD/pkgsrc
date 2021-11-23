# $NetBSD: Makefile,v 1.2 2021/11/23 07:30:52 pho Exp $

DISTNAME=	yadm-3.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=TheLocehiliosan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yadm.io/
COMMENT=	Yet Another Dotfiles Manager
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash:run gawk:run pax tar:run
NO_BUILD=	yes

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

# yadm by default initially launches as a /bin/sh script and then
# exec's bash that happens to be in $PATH. Prevent it from doing that.
REPLACE_BASH+=	yadm

# Embed paths to external programs and don't try to find ones in $PATH.
YADM_PROGS=	# empty
YADM_PROGS+=	GIT_PROGRAM="${PREFIX:Q}/bin/git"
YADM_PROGS+=	AWK_PROGRAM=("${TOOLS_PATH.gawk:Q}")

# These programs are not in pkgsrc (yet).
YADM_PROGS+=	GIT_CRYPT_PROGRAM="/nonexistent"
YADM_PROGS+=	TRANSCRYPT_PROGRAM="/nonexistent"
YADM_PROGS+=	J2CLI_PROGRAM="/nonexistent"
YADM_PROGS+=	ENVTPL_PROGRAM="/nonexistent"
YADM_PROGS+=	ESH_PROGRAM="/nonexistent"

SUBST_CLASSES+=		progs
SUBST_STAGE.progs=	pre-configure
SUBST_FILES.progs=	yadm
# We can't use .for here, because variables like TOOLS_PATH.* are not
# defined yet. Even bsd.prefs.mk doesn't define them.
SUBST_SED.progs+=	${YADM_PROGS:@pair@-e 's|${pair:C/=.*//}=.*$$|${pair}|'@}

# These scripts are intended to be copied into yadm repositories which
# can possibly be cloned onto systems without pkgsrc. It is therefore
# inappropriate to use pkgsrc-specific interpreter paths.
REPLACE_INTERPRETER+=		env-bash
REPLACE.env-bash.old=		.*bash
REPLACE.env-bash.new=		${TOOLS_PATH.env} bash
REPLACE_FILES.env-bash=		contrib/bootstrap/bootstrap-in-dir
REPLACE_FILES.env-bash+=	contrib/hooks/parsing_full_command_example/pre_log

.include "options.mk"

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/completions
INSTALLATION_DIRS+=	share/zsh/site-functions
INSTALLATION_DIRS+=	share/doc/yadm
INSTALLATION_DIRS+=	share/examples/yadm
do-install:
	${INSTALL_SCRIPT} \
		"${WRKSRC}/yadm" \
		"${DESTDIR}${PREFIX}/bin/"
	${INSTALL_MAN} \
		"${WRKSRC}/yadm.1" \
		"${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/"
	${INSTALL_DATA} \
		"${WRKSRC}/completion/bash/yadm" \
		"${DESTDIR}${PREFIX}/share/bash-completion/completions/"
	${INSTALL_DATA} \
		"${WRKSRC}/completion/fish/yadm.fish" \
		"${DESTDIR}${PREFIX}/share/fish/completions/"
	${INSTALL_DATA} \
		"${WRKSRC}/completion/zsh/_yadm" \
		"${DESTDIR}${PREFIX}/share/zsh/site-functions/"
	for f in CHANGES CONTRIBUTORS LICENSE README.md; do \
		${INSTALL_DATA} \
			"${WRKSRC}/$${f}" \
			"${DESTDIR}${PREFIX}/share/doc/yadm/"; \
	done
	cd "${WRKSRC}/contrib" && \
		${PAX} -wr . "${DESTDIR}${PREFIX}/share/examples/yadm"

.include "../../mk/bsd.pkg.mk"
