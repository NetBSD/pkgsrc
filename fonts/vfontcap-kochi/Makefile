# $NetBSD: Makefile,v 1.6 2003/08/20 04:49:28 kei Exp $

DISTNAME=		vfontcap-kochi-0.0
WRKSRC=			${WRKDIR}
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		Configuration file for VFlib to use kochi-ttf

DEPENDS+=		ja-vflib-lib-[0-9]*:../../print/ja-vflib-lib
DEPENDS+=		kochi-ttf-[0-9]*:../../fonts/kochi-ttf

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		YES
NO_BUILD=		YES
USE_X11=		YES # kochi font defines this as well.

USE_PKGINSTALL=		YES

VFONTCAPDIR=		${PREFIX}/share/VFlib/2.24.2
FILES_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}

do-configure:
	${SED} -e 's,@X11PREFIX@,${X11PREFIX},g' ${FILESDIR}/vfontcap \
		> ${WRKSRC}/vfontcap

do-install:
	${INSTALL_DATA} ${WRKDIR}/vfontcap ${VFONTCAPDIR}

.include "../../mk/bsd.pkg.mk"
