# $NetBSD: Makefile,v 1.2 2004/12/02 12:27:08 adam Exp $

DISTNAME=	gnugk-2.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openh323gk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnugk.org/
COMMENT=	H.323 Gatekeeper

USE_BUILDLINK3=		yes
USE_GNU_TOOLS=		make
USE_PKGINSTALL=         yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_PTLIB_CONFIG=${PREFIX}/bin/ptlib-config
CONFIGURE_ENV+=		PWLIBDIR=${PREFIX}/share/pwlib
CONFIGURE_ENV+=		OPENH323DIR=${PREFIX}/share/openh323

CFLAGS+=	-fexceptions
MAKE_ENV+=	LIBTOOL="${LIBTOOL}" SYSLIBDIR="${PREFIX}/lib"

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/gnugk.ini ${PKG_SYSCONFDIR}/gnugk.ini
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
