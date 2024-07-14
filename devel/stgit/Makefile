# $NetBSD: Makefile,v 1.52 2024/07/14 06:24:52 wiz Exp $

DISTNAME=	stgit-2.4.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stacked-git/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	terin@terinstock.com
HOMEPAGE=	https://stacked-git.github.io/
COMMENT=	Stacked GIT
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	asciidoc>=8:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	git-base>=1.5.2:../../devel/git-base

USE_TOOLS+=	gmake perl pkg-config

REPLACE_PERL+=	Documentation/build-docdep.perl
REPLACE_PERL+=	Documentation/cat-texi.perl
REPLACE_PERL+=	Documentation/fix-texi.perl
MAKE_ENV+=	PERL_PATH=${PERL5}

INSTALLATION_DIRS=	bin man share

INSTALL_MAKE_FLAGS+=	STG_PROFILE=release
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	${DESTDIR:DDESTDIR=}${DESTDIR}

INSTALL_TARGET=		install
INSTALL_TARGET+=	install-man
INSTALL_TARGET+=	install-html
INSTALL_TARGET+=	install-completion

do-install:
	${RUN} ${_ULIMIT_CMD}						\
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} 	\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
			-f ${MAKE_FILE} ${INSTALL_TARGET}

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
