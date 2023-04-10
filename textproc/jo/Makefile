# $NetBSD: Makefile,v 1.17 2023/04/10 13:54:21 schmonz Exp $

DISTNAME=	jo-1.9
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpmens/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpmens/jo
COMMENT=	JSON output from a shell
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c99
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	bashcompdir=${PREFIX}/share/bash-completion/completions
CONFIGURE_ENV+=	ac_cv_path_PANDOC=none

TEST_TARGET=	check

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/bash-completion/completions/${PKGBASE}.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
