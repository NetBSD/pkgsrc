# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:59 jmmv Exp $

DISTNAME=		vfontcap-kochi-0.0
WRKSRC=			${WRKDIR}
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@netbsd.org
COMMENT=		configuration file for VFlib to use kochi-ttf

DEPENDS+=		ja-vflib-lib-*:../../print/ja-vflib-lib
DEPENDS+=		kochi-ttf-*:../../fonts/kochi-ttf

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		YES
NO_BUILD=		YES

VFONTCAPDIR=		${PREFIX}/share/VFlib/2.24.2
FILES_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}

do-configure:
	${CP} ${FILESDIR}/vfontcap ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKDIR}/vfontcap ${VFONTCAPDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
