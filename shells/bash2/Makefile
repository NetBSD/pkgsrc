# $NetBSD: Makefile,v 1.57 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=	bash-2.05b
PKGNAME=	bash-2.05.2.7
PKGREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

PATCH_SITES=	${MASTER_SITES:=bash-2.05b-patches/}
PATCHFILES=	bash205b-001 bash205b-002 bash205b-003 bash205b-004 \
		bash205b-005 bash205b-006 bash205b-007

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

CONFLICTS=	static-bash-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT='${INSTALL_SCRIPT}'
TEST_TARGET=		test

PKG_SHELL=		${PREFIX}/bin/bash

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
.include "../../mk/bsd.pkg.mk"
