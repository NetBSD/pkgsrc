# $NetBSD: Makefile,v 1.1.1.1 2011/11/20 19:11:49 ryoon Exp $
#

DISTNAME=	sitaramc-gitolite-v2.2-0-g15b17d7
PKGNAME=	gitolite-2.2
CATEGORIES=	devel net
MASTER_SITES=	-https://github.com/sitaramc/gitolite/tarball/v2.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sitaramc/gitolite/wiki
COMMENT=	Gitolite allows you to host Git repositories easily and securely
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

USE_LANGUAGES=	# none
USE_TOOLS+=	perl bash

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

WRKSRC=		${WRKDIR}/sitaramc-gitolite-0ffadc1

NO_BUILD=	yes

REPLACE_PERL=	src/gl-* src/sshkeys-lint hooks/common/update
REPLACE_BASH=	src/gl-* hooks/common/*

do-install:
	${RM} ${WRKSRC}/src/gl-system-install.orig
	${WRKSRC}/src/gl-system-install ${PREFIX}/bin \
		${PREFIX}/share/gitolite/conf ${PREFIX}/share/gitolite/hooks \
		${DESTDIR}

.include "../../mk/bsd.pkg.mk"
