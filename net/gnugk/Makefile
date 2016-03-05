# $NetBSD: Makefile,v 1.19 2016/03/05 11:29:05 jperkin Exp $

DISTNAME=	gnugk-2.2.0
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openh323gk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnugk.org/
COMMENT=	H.323 Gatekeeper

PKG_DESTDIR_SUPPORT=	destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_PTLIB_CONFIG=${BUILDLINK_PREFIX.pwlib}/bin/ptlib-config
CONFIGURE_ENV+=		PWLIBDIR=${BUILDLINK_PREFIX.pwlib}/share/pwlib
CONFIGURE_ENV+=		OPENH323DIR=${BUILDLINK_PREFIX.openh323}/share/openh323

CFLAGS+=	-fexceptions
MAKE_ENV+=	LIBTOOL=${LIBTOOL:Q} SYSLIBDIR="${PREFIX}/lib"

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
RCD_SCRIPTS=		gnugk

INSTALL_MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC}/docs; for f in `find . -type f -print` ; do \
	  ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}; done
	cd ${WRKSRC}/etc; for f in `find . -type f -print` ; do \
	  ${INSTALL_DATA} $$f ${DESTDIR}${EGDIR}; done

.include "../../net/openh323/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
