# $NetBSD: Makefile,v 1.1.1.1 2004/10/21 03:11:14 xtraeme Exp $
#

DISTNAME=	bash-3.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

CONFLICTS=	static-bash-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT='${INSTALL_SCRIPT}'
TEST_TARGET=		test

INFO_FILES=		bash.info

PKG_SHELL=		${PREFIX}/bin/bash

USE_GNU_READLINE=	yes

# All features enabled by default.
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--enable-progcomp
CONFIGURE_ARGS+=	--enable-process-substitution	
CONFIGURE_ARGS+=	--enable-multibyte
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

.if defined(BASH_STATIC) && !empty(BASH_STATIC:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	static
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.bash
PKG_SUPPORTED_OPTIONS=	static
.include "../../mk/bsd.options.mk"

##
## Static link
##
.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static-link
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/bash.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bashbug.1 ${PREFIX}/man/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
