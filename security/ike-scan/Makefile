# $NetBSD: Makefile,v 1.3 2005/01/14 08:36:54 adrianp Exp $
#

DISTNAME=	ike-scan-1.7
CATEGORIES=	security
MASTER_SITES=	http://www.nta-monitor.com/ike-scan/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nta-monitor.com/ike-scan/
COMMENT=	Fingerprinting IKE implementation

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

CONFIGURE_ARGS+=	--with-openssl

SUBST_CLASSES=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	ike-scan.1
SUBST_SED.man=		-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.man=	"Fixing man pages."

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ike-scan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ike-scan/README

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
