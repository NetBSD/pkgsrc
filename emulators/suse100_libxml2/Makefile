# $NetBSD: Makefile,v 1.3 2007/04/19 15:30:21 xtraeme Exp $

DISTNAME=	suse_libxml2-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUSE100}
DISTFILES=	${RPMFILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.suse.com/
COMMENT=	Linux compatibility package for the libxml2 library

DEPENDS+=	suse_base-${SUSE_VERSION}{,nb*}:../../emulators/suse100_base

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

SUSE_INCLUDE_MAKEFILE_ARCH=	yes

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
