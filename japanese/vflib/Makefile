# $NetBSD: Makefile,v 1.2 1999/09/03 05:43:00 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.20 1999/05/03 01:58:33 steve Exp $

DISTNAME=	VFlib2-2.24.2
PKGNAME=	ja-vflib-2.24.2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/	\
		ftp://ftp.kuis.kyoto-u.ac.jp/TeX/watanabe-jfonts/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} watanabe-vf${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://TypeHack.aial.hiroshima-u.ac.jp/VFlib/

DEPENDS=	freetype-1.1:../../graphics/freetype

VFLIB_VERSION=	2.24.2
PLIST_SUBST+=	VFLIB_VERSION=${VFLIB_VERSION} \
		VFLIB_SO_VERSION=${VFLIB_VERSION:C/^2.//}

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

post-configure:
	@${RM} -r ${WRKSRC}/libtool
	@${LN} -s ${LIBTOOL} ${WRKSRC}/libtool

post-build:
.for f in vfontcap vfontcap.bdf
	@(cd ${WRKSRC}; \
	    ${MV} ${f} ${f}.orig;	\
	    ${SED} -e 's|\$${PREFIX}|${PREFIX}|g' ${f}.orig > ${f};	\
	    ${RM} ${f}.orig)
.endfor

pre-install:
	@(cd ${WRKSRC}/tools; \
	    ${INSTALL_SCRIPT} fmtest disol kban vfperf vftest ${PREFIX}/bin)
	@(cd ${WRKSRC}; \
	  ${MKDIR} ${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} COPYING COPYING.LIB README.txt.JP_EUC \
		${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} -R jTeX ${PREFIX}/share/VFlib/${VFLIB_VERSION})
	@${MKDIR} ${PREFIX}/share/fonts/watanabe_font
	@${GTAR} -C ${PREFIX}/share/fonts/watanabe_font \
		-xzf ${DISTDIR}/watanabe-vf${EXTRACT_SUFX}

post-install:
	${MV} ${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
