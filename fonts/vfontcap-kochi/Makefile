# $NetBSD: Makefile,v 1.20 2012/10/03 18:28:32 asau Exp $

DISTNAME=		vfontcap-kochi-0.0
PKGREVISION=		3
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Configuration file for VFlib to use kochi-ttf

DEPENDS+=		ja-vflib-lib-[0-9]*:../../print/ja-vflib-lib
DEPENDS+=		kochi-ttf-[0-9]*:../../fonts/kochi-ttf

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

EVAL_PREFIX+=		KOCHI_TTF_PREFIX=kochi-ttf

VFONTCAPDIR=		share/VFlib/2.24.2
FILES_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}
MESSAGE_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}
PLIST_SUBST+=		VFONTCAPDIR=${VFONTCAPDIR}

INSTALLATION_DIRS=	${VFONTCAPDIR}

do-configure:
	${SED}	-e "s,@KOCHI_TTF_PREFIX@,${KOCHI_TTF_PREFIX},g"		\
		${FILESDIR}/vfontcap > ${WRKSRC}/vfontcap

do-install:
	${INSTALL_DATA} ${WRKSRC}/vfontcap				\
		${DESTDIR}${PREFIX}/${VFONTCAPDIR}/vfontcap.kochi-ttf

.include "../../mk/bsd.pkg.mk"
