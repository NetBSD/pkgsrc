# $NetBSD: Makefile,v 1.24 2005/04/11 21:44:48 tv Exp $
#

DISTNAME=       cpio-2.5
PKGNAME=	g${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_MAKEINFO=	yes

INFO_FILES=	cpio.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=		-lgnumalloc
.endif

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/bsd.pkg.mk"
