# $NetBSD: Makefile,v 1.19 2003/08/09 10:27:40 seb Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
LIBS+=		-lgnumalloc

INFO_FILES=	cpio.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
