# $NetBSD: Makefile,v 1.6 2003/11/12 03:39:41 jschauma Exp $
#

DISTNAME=	docsis-0.7.5-RELEASE
PKGNAME=	${DISTNAME:S/-RELEASE//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docsis/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://docsis.sourceforge.net/
COMMENT=	Utility for manipulating DOCSIS-compliant cable modems

BUILD_DEPENDS+=	bison>=1.25:../../devel/bison
USE_BUILDLINK2=	# defined

ALL_TARGET=	docsis

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/docsis ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/docsis
		${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/docsis
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/docsis
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/docsis
		cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/docsis

.include "../../security/openssl/buildlink2.mk"
.include "../../net/ucd-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
