# $NetBSD: Makefile,v 1.1.1.1 2004/10/09 20:47:21 mjl Exp $
#

DISTNAME=		gnugk-2.0.8
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openh323gk/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://openh323gk.sourceforge.net/
COMMENT=		H.323 Gatekeeper

WRKSRC=			${WRKDIR}/openh323gk
USE_BUILDLINK3=		yes
USE_GNU_TOOLS=		make
USE_PKGINSTALL=         YES
NO_CONFIGURE=		YES
ALL_TARGET=		opt

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/gnugk.ini ${PKG_SYSCONFDIR}/gnugk.ini
RCD_SCRIPTS=	gnugk

MAKE_ENV+=		PWLIBDIR=${PREFIX} OPENH323DIR=${PREFIX} SYSLIBDIR=${PREFIX}/lib
MAKE_ENV+=		NO_RADIUS=1 NO_LDAP=1 NO_MYSQL=1 NO_PGSQL=1 LIBTOOL=${LIBTOOL}

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/docs; \
	for f in `find . -type f -print` ; do \
	  ${INSTALL_DATA} $$f ${PREFIX}/doc/${PKGBASE}; done
	cd ${WRKSRC}/etc; \
	for f in `find . -type f -print` ; do \
	  ${INSTALL_DATA} $$f ${EGDIR}; done

.include "../../devel/pwlib/buildlink3.mk"
.include "../../net/openh323/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
