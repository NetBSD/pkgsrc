# $NetBSD: Makefile,v 1.14 2008/01/18 05:08:42 tnn Exp $

DISTNAME=	gnugk-2.2.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openh323gk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnugk.org/
COMMENT=	H.323 Gatekeeper

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_PTLIB_CONFIG=${PREFIX}/bin/ptlib-config
CONFIGURE_ENV+=		PWLIBDIR=${PREFIX}/share/pwlib
CONFIGURE_ENV+=		OPENH323DIR=${PREFIX}/share/openh323

CFLAGS+=	-fexceptions
MAKE_ENV+=	LIBTOOL=${LIBTOOL:Q} SYSLIBDIR="${PREFIX}/lib"

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
RCD_SCRIPTS=		gnugk

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC}/docs; for f in `find . -type f -print` ; do \
	  ${INSTALL_DATA} $$f ${PREFIX}/share/doc/${PKGBASE}; done
	cd ${WRKSRC}/etc; for f in `find . -type f -print` ; do \
	  ${INSTALL_DATA} $$f ${EGDIR}; done

.include "../../net/openh323/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
