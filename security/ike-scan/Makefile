# $NetBSD: Makefile,v 1.17 2014/02/12 23:18:32 tron Exp $

DISTNAME=	ike-scan-1.9
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.nta-monitor.com/tools/ike-scan/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nta-monitor.com/tools/ike-scan/
COMMENT=	Fingerprinting IKE implementation

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	ike-scan.1
SUBST_SED.man=		-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.man=	Fixing man pages.

INSTALLATION_DIRS+=	share/doc/ike-scan

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ike-scan/README

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
