# $NetBSD: Makefile,v 1.16 2018/12/03 19:45:22 schmonz Exp $
#

DISTNAME=		syncdir-1.0
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/syncdir/
COMMENT=		Synchronous open, link, rename, and unlink
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes

LIBTOOL_PATCH=		syncdir-1.0-libtoolize-20181112.patch
PATCHFILES+=		${LIBTOOL_PATCH}
SITES.${LIBTOOL_PATCH}=	https://schmonz.com/qmail/syncdirlibtool/

DLSYM_PATCH=		syncdir-1.0-libtoolize-20181112-dlsym-20181203.patch
PATCHFILES+=		${DLSYM_PATCH}
SITES.${DLSYM_PATCH}=	https://schmonz.com/qmail/syncdirdlsym/

INSTALLATION_DIRS=	lib

.include "../../mk/bsd.pkg.mk"
