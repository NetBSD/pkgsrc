# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:52 jlam Exp $

DISTNAME=		vfontcap-kochi-0.0
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		Configuration file for VFlib to use kochi-ttf

DEPENDS+=		ja-vflib-lib-[0-9]*:../../print/ja-vflib-lib
DEPENDS+=		kochi-ttf-[0-9]*:../../fonts/kochi-ttf

WRKSRC=			${WRKDIR}
EXTRACT_ONLY=		# empty
NO_CHECKSUM=		YES
NO_BUILD=		YES

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

VFONTCAPDIR=		${PREFIX}/share/VFlib/2.24.2
FILES_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}

INSTALLATION_DIRS=	share/VFlib/2.24.2

do-configure:
	${SED} -e 's,@X11PREFIX@,${X11PREFIX},g' ${FILESDIR}/vfontcap \
		> ${WRKSRC}/vfontcap

do-install:
	${INSTALL_DATA} ${WRKDIR}/vfontcap ${VFONTCAPDIR}

.include "../../mk/bsd.pkg.mk"
