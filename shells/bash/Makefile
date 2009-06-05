# $NetBSD: Makefile,v 1.45 2009/06/05 23:32:00 hasso Exp $

BASH_VERSION=		4.0
BASH_PATCHLEVEL=	24

DISTNAME=	bash-${BASH_VERSION}
PKGNAME=	bash-${BASH_VERSION}.${BASH_PATCHLEVEL}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

PATCH_SITES=	${MASTER_SITES:=bash-4.0-patches/}
PATCHFILES+=	bash40-001 bash40-002 bash40-003 bash40-004 bash40-005
PATCHFILES+=	bash40-006 bash40-007 bash40-008 bash40-009 bash40-010
PATCHFILES+=	bash40-011 bash40-012 bash40-013 bash40-014 bash40-015
PATCHFILES+=	bash40-016 bash40-017 bash40-018 bash40-019 bash40-020
PATCHFILES+=	bash40-021 bash40-022 bash40-023 bash40-024

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

CONFLICTS=	static-bash-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo bison
USE_PKGLOCALEDIR=	yes
TEXINFO_REQD=		4.1
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
CONFIGURE_ARGS=		LOCAL_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:M*:Q}
CPPFLAGS+=		-DDEFAULT_PATH_VALUE="\"/usr/bin:/bin:${LOCALBASE}/bin:/usr/local/bin\""
MAKE_JOBS_SAFE=		no
TEST_TARGET=		test

INFO_FILES=		YES # PLIST
PKG_SHELL=		bin/bash
INSTALLATION_DIRS=	${PKGMANDIR}/man1

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
PKG_SUPPORTED_OPTIONS=	static

.include "../../mk/bsd.options.mk"

##
## Static link
##
.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static-link
BUILDLINK_DEPMETHOD.gettext=	build
BUILDLINK_DEPMETHOD.readline=	build
.endif

# Use "readline" package on Darwin to avoid link erros.
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=		--with-installed-readline

USE_GNU_READLINE=		yes
BUILDLINK_API_DEPENDS.readline+=	readline>=6.0

.include "../../devel/readline/buildlink3.mk"
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/bash.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bashbug.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
