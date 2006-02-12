# $NetBSD: Makefile,v 1.29 2006/02/12 01:44:28 seb Exp $
#

DISTNAME=       cpio-2.6
PKGREVISION=	2
PKGNAME=	g${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_MAKEINFO=	yes

TEST_TARGET=	check

INFO_FILES=	cpio.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=		-lgnumalloc
.endif

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
