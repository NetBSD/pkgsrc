# $NetBSD: Makefile,v 1.34 2007/02/18 12:21:59 wiz Exp $

DISTNAME=	bash-3.2
PKGNAME=	bash-3.2.9
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

PATCH_SITES=	${MASTER_SITES:=bash-3.2-patches/}
PATCHFILES=	bash32-001
PATCHFILES+=	bash32-002
PATCHFILES+=	bash32-003
PATCHFILES+=	bash32-004
PATCHFILES+=	bash32-005
PATCHFILES+=	bash32-006
PATCHFILES+=	bash32-007
PATCHFILES+=	bash32-008
PATCHFILES+=	bash32-009

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

CONFLICTS=	static-bash-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		makeinfo yacc
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
	${INSTALL_MAN} ${WRKSRC}/doc/bash.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bashbug.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
