# $NetBSD: Makefile,v 1.23 2023/10/24 22:10:49 wiz Exp $

DISTNAME=	ike-scan-1.9
PKGREVISION=	7
CATEGORIES=	security
#MASTER_SITES=	http://www.nta-monitor.com/tools/ike-scan/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.nta-monitor.com/tools/ike-scan/
COMMENT=	Fingerprinting IKE implementation

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	ike-scan.1
SUBST_SED.man=		-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.man=	Fixing man pages.

INSTALLATION_DIRS+=	share/doc/ike-scan

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ike-scan/README

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
