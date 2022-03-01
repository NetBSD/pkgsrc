# $NetBSD: Makefile,v 1.19 2022/03/01 17:49:46 schmonz Exp $
#

DISTNAME=		syncdir-1.1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/syncdir/
COMMENT=		Synchronous open, link, rename, and unlink
LICENSE=		unlicense

USE_LIBTOOL=		yes

LIBTOOL_PATCH=		syncdir-1.0-libtoolize-20181112.patch
PATCHFILES+=		${LIBTOOL_PATCH}
SITES.${LIBTOOL_PATCH}=	https://schmonz.com/qmail/syncdirlibtool/

DLSYM_PATCH=		syncdir-1.0-libtoolize-20181112-dlsym-20181203.1.patch
PATCHFILES+=		${DLSYM_PATCH}
SITES.${DLSYM_PATCH}=	https://schmonz.com/qmail/syncdirdlsym/

INSTALLATION_DIRS=	lib

SUBST_CLASSES+=		space
SUBST_STAGE.space=	post-extract
SUBST_FILES.space=	syncdir.c
SUBST_SED.space=	-e 's|if(SYS_RENAME(oldpath|if (SYS_RENAME(oldpath|'
SUBST_SED.space+=	-e 's|if(fdirsyncfn(newpath|if (fdirsyncfn(newpath|'

.include "../../mk/bsd.pkg.mk"
