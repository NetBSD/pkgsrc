# $NetBSD: Makefile,v 1.2 2002/07/11 16:09:36 agc Exp $
#

DISTNAME=	binutils-2.11.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/directory/binutils.html
COMMENT=	GNU binary utilities

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCHFILES=	binutils-NetBSD-diff-20020418.patch.bz2
PATCH_SITES=	${MASTER_SITE_LOCAL}
.elif ${OPSYS} == "SunOS"
PLIST_SRC=	${PKGDIR}/PLIST.${OPSYS}
.endif

.include "../../mk/bsd.pkg.mk"
