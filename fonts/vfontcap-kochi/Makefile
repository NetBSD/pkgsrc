# $NetBSD: Makefile,v 1.5 2003/07/30 10:41:23 jmmv Exp $

DISTNAME=		vfontcap-kochi-0.0
WRKSRC=			${WRKDIR}
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		Configuration file for VFlib to use kochi-ttf

DEPENDS+=		ja-vflib-lib-*:../../print/ja-vflib-lib
DEPENDS+=		kochi-ttf-*:../../fonts/kochi-ttf

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		YES
NO_BUILD=		YES

USE_PKGINSTALL=		YES

VFONTCAPDIR=		${PREFIX}/share/VFlib/2.24.2
FILES_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}

do-configure:
	${CP} ${FILESDIR}/vfontcap ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKDIR}/vfontcap ${VFONTCAPDIR}

.include "../../mk/bsd.pkg.mk"
