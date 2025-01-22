# $NetBSD: Makefile,v 1.1 2025/01/22 09:25:18 adam Exp $

DISTNAME=	git-secret-0.5.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=sobolevn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sobolevn/git-secret
COMMENT=	Git subcommand to store your private data inside a git repository
LICENSE=	mit

DEPENDS+=	gawk-[0-9]*:../../lang/gawk
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2

USE_TOOLS+=	bash:run

REPLACE_BASH+=	src/*.sh
REPLACE_BASH+=	src/commands/*.sh
REPLACE_BASH+=	src/_utils/*.sh
REPLACE_BASH+=	utils/*.sh

SUBST_CLASSES+=		gpgpath
SUBST_STAGE.gpgpath=	pre-configure
SUBST_MESSAGE.gpgpath=	Fixing gpg path.
SUBST_FILES.gpgpath=	src/_utils/_git_secret_tools.sh
SUBST_SED.gpgpath=	-e 's,SECRETS_GPG_COMMAND:="gpg",SECRETS_GPG_COMMAND:="${PREFIX}/bin/gpg2",'

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Fixing paths for man pages.
SUBST_FILES.mandir=	utils/install.sh
SUBST_SED.mandir=	-e 's,share/man,${PKGMANDIR},g'

.include "../../mk/bsd.pkg.mk"
