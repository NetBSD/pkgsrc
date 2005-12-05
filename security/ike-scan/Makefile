# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:56 rillig Exp $

DISTNAME=	ike-scan-1.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.nta-monitor.com/ike-scan/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nta-monitor.com/ike-scan/
COMMENT=	Fingerprinting IKE implementation

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	ike-scan.1
SUBST_SED.man=		-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.man=	"Fixing man pages."

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ike-scan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ike-scan/README

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
