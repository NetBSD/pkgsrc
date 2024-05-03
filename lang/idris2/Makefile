# $NetBSD: Makefile,v 1.2 2024/05/03 06:47:18 pho Exp $

# ABI version: See ${WRKSRC}/src/Core/Binary.idr (ttcVersion)
IDRIS2_TTC_VERSION=	2023090800

DISTNAME=	idris2-0.7.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=idris-lang/}
GITHUB_PROJECT=	Idris2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.idris-lang.org/
COMMENT=	Functional Programming Language with Dependent Types
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:S/idris2/Idris2/}

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

#
# Targets (See ${WRKSRC}/INSTALL.mk)
#
BUILD_TARGET=	bootstrap
MAKE_FLAGS=	SCHEME=chezscheme
TEST_TARGET=	test

#
# Build
#
post-build:
	${WRKSRC}/build/exec/idris2 --bash-completion-script idris2 > ${WRKDIR}/idris2.bash
	( \
		${ECHO} '#compdef idris2'; \
		${ECHO} 'autoload -U +X bashcompinit && bashcompinit'; \
		${CAT} ${WRKDIR}/idris2.bash; \
	) > ${WRKDIR}/idris2.zsh

#
# Install
#
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions
post-install:
	${INSTALL_DATA} ${WRKDIR}/idris2.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/idris2
	${INSTALL_DATA} ${WRKDIR}/idris2.zsh ${DESTDIR}${PREFIX}/share/zsh/site-functions/_idris2

# These files are not only unnecessary but also contain references to
# ${WRKDIR}. Remove them all.
	for f in compileChez idris2-boot.so idris2-boot.ss; do \
		${RM} -f ${DESTDIR}${PREFIX}/bin/idris2_app/$$f; \
	done

# bin/idris2 is a shell script to invoke an actual executable but the said
# executable is at bin/idris2_app/idris2.so. We really don't want it to
# create a subdirectory in bin because that confuses zsh. pkglint doesn't
# like it also.
	${MV} ${DESTDIR}${PREFIX}/bin/idris2_app ${DESTDIR}${PREFIX}/libexec

SUBST_CLASSES+=		app
SUBST_STAGE.app=	post-install
SUBST_FILES.app=	${DESTDIR}${PREFIX}/bin/idris2
SUBST_FILTER_CMD.app=	${AWK} '/fi/	{ print $$0; print "DIR=$$DIR/../libexec"; next } \
					{ print $$0 }'

# These .so files aren't shared libraries.
CHECK_SHLIBS_SKIP+=	${PKGNAME_NOREV}/*.so
CHECK_SHLIBS_SKIP+=	libexec/idris2_app/idris2.so

#
# PLIST
#
PRINT_PLIST_AWK+=	{ gsub("${PKGNAME_NOREV}", "$${PKGNAME_NOREV}") }
PRINT_PLIST_AWK+=	{ gsub("${IDRIS2_TTC_VERSION}", "$${IDRIS2_TTC_VERSION}") }
PLIST_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV}
PLIST_SUBST+=		IDRIS2_TTC_VERSION=${IDRIS2_TTC_VERSION}

#
# Dependencies
#
# It uses Chez Scheme at run time in order to compile Scheme source
# (compiled from Idris 2) into native code.
DEPENDS+=	chezscheme-[0-9]*:../../lang/chezscheme

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
