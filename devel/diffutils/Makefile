# $NetBSD: Makefile,v 1.10 2003/06/02 01:20:52 jschauma Exp $
#

DISTNAME=		diffutils-2.8.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=diffutils/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/diffutils/diffutils.html
COMMENT=		GNU diff utilities - find the differences between files

GNU_CONFIGURE=		YES
INFO_FILES=		diff.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
