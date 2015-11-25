# $NetBSD: Makefile,v 1.22 2015/11/25 12:50:15 jperkin Exp $

DISTNAME=		vfontcap-kochi-0.0
PKGREVISION=		4
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Configuration file for VFlib to use kochi-ttf

DEPENDS+=		ja-vflib-lib-[0-9]*:../../print/ja-vflib-lib
DEPENDS+=		kochi-ttf-[0-9]*:../../fonts/kochi-ttf

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

VFONTCAPDIR=		share/VFlib/2.24.2
FILES_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}
MESSAGE_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}
PLIST_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}

INSTALLATION_DIRS=	${VFONTCAPDIR}

do-configure:
	${SED}	-e "s,@KOCHI_TTF_PREFIX@,${LOCALBASE},g"		\
		${FILESDIR}/vfontcap > ${WRKSRC}/vfontcap

do-install:
	${INSTALL_DATA} ${WRKSRC}/vfontcap				\
		${DESTDIR}${PREFIX}/${VFONTCAPDIR}/vfontcap.kochi-ttf

.include "../../mk/bsd.pkg.mk"
