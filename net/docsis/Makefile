# $NetBSD: Makefile,v 1.1.1.1 2002/06/25 04:12:52 grant Exp $
#

DISTNAME=	docsis-0.7.5-RELEASE
PKGNAME=	${DISTNAME:S/-RELEASE//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docsis/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://docsis.sourceforge.net/
COMMENT=	utility for manipulating DOCSIS-compliant cable modems

BUILD_DEPENDS+=		bison>=1.25:../../devel/bison
USE_BUILDLINK_ONLY=	# defined

ALL_TARGET=		docsis

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/docsis ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/docsis
		${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/docsis
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/docsis
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/docsis
		cd ${WRKSRC}/examples; ${PAX} -rw . ${PREFIX}/share/examples/docsis

.include "../../security/openssl/buildlink.mk"
.include "../../net/ucd-snmp/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
