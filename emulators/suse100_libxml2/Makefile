# $NetBSD: Makefile,v 1.1.1.1 2006/06/13 11:30:48 salo Exp $

DISTNAME=	suse_libxml2-${SUSE_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUSE100}
DISTFILES=	${RPMFILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.suse.com/
COMMENT=	Linux compatibility package for the libxml2 library

DEPENDS+=	suse_base>=${SUSE_VERSION}:../../emulators/suse100_base

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
