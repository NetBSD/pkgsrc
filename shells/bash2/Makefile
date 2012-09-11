# $NetBSD: Makefile,v 1.82 2012/09/11 23:25:07 asau Exp $
#

DISTNAME=	bash-2.05b
PKGNAME=	bash-2.05.2.7
PKGREVISION=	11
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

PATCH_SITES=	${MASTER_SITES:=bash-2.05b-patches/}
PATCHFILES=	bash205b-001 bash205b-002 bash205b-003 bash205b-004 \
		bash205b-005 bash205b-006 bash205b-007

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell (version 2)

CONFLICTS=	static-bash-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_READLINE=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-installed-readline
MAKE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
CPPFLAGS+=		-DDEFAULT_PATH_VALUE="\"/usr/bin:/bin:${LOCALBASE}/bin:/usr/local/bin\""
TEST_TARGET=		test
MAKE_JOBS_SAFE=		no
BROKEN_GETTEXT_DETECTION=	yes

PKG_SHELL=		bin/bash

.include "../../mk/bsd.prefs.mk"

CFLAGS.Interix+=	-DUSE_POSIX_GLOB_LIBRARY

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

BUILDLINK_API_DEPENDS.readline+=	readline>=4.3

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/bash.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bashbug.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
