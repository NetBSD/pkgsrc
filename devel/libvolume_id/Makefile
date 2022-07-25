# $NetBSD: Makefile,v 1.12 2022/07/25 11:12:23 wiz Exp $

DISTNAME=		libvolume_id-0.81.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.marcuscom.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Library to provide file system type information
LICENSE=		gnu-gpl-v2

INSTALLATION_DIRS=	include lib lib/pkgconfig
USE_TOOLS+=		gmake

USE_LIBTOOL=	yes

MAKE_ENV+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_ENV+=		INSTALL_LIB=${INSTALL_LIB:Q}

.include "../../mk/bsd.pkg.mk"
