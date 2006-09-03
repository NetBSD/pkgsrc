# $NetBSD: Makefile,v 1.27 2006/09/03 08:30:42 wiz Exp $

DISTNAME=	bash-3.1
PKGNAME=	bash-3.1pl17
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

PATCH_SITES=	${MASTER_SITES:=bash-3.1-patches/}
PATCHFILES=	bash31-001 bash31-002 bash31-003 bash31-004 \
		bash31-005 bash31-006 bash31-007 bash31-008 \
		bash31-009 bash31-010 bash31-011 bash31-012 \
		bash31-013 bash31-014 bash31-015 bash31-016 \
		bash31-017   

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

CONFLICTS=	static-bash-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		makeinfo yacc
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
CONFIGURE_ARGS=		LOCAL_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}
CPPFLAGS+=		-DDEFAULT_PATH_VALUE="\"/usr/bin:/bin:/usr/pkg/bin:/usr/local/bin\""
TEST_TARGET=		test

INFO_FILES=		# PLIST
PKG_SHELL=		bin/bash

# All features enabled by default.
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--enable-progcomp
CONFIGURE_ARGS+=	--enable-process-substitution
CONFIGURE_ARGS+=	--enable-job-control
CONFIGURE_ARGS+=	--enable-history
CONFIGURE_ARGS+=	--enable-help-builtin
CONFIGURE_ARGS+=	--enable-extended-glob
CONFIGURE_ARGS+=	--enable-dparen-arithmetic
CONFIGURE_ARGS+=	--enable-directory-stack
CONFIGURE_ARGS+=	--enable-debugger
CONFIGURE_ARGS+=	--enable-cond-regexp
CONFIGURE_ARGS+=	--enable-alias
CONFIGURE_ARGS+=	--enable-brace-expansion
CONFIGURE_ARGS+=	--enable-array-variables

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.bash
PKG_SUPPORTED_OPTIONS=	multibyte static
PKG_SUGGESTED_OPTIONS=	multibyte

.include "../../mk/bsd.options.mk"

##
## Static link
##
.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static-link
BUILDLINK_DEPMETHOD.gettext=	build
BUILDLINK_DEPMETHOD.readline=	build
.endif

##
## Multibyte support
##
.if empty(PKG_OPTIONS:Mmultibyte)
CONFIGURE_ENV+=	ac_cv_type_wctype_t=no
.endif

# the code has problems with older versions of yacc
.if !empty(LOWER_OPSYS:Mirix5*)
USE_TOOLS+=	bison
.endif

# Use "readline" package on Darwin to avoid link erros.
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=		--with-installed-readline

USE_GNU_READLINE=		yes
BUILDLINK_API_DEPENDS.readline+=	readline>=4.3

.include "../../devel/readline/buildlink3.mk"
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/bash.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bashbug.1 ${PREFIX}/man/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
