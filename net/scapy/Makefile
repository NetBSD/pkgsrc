# $NetBSD: Makefile,v 1.5 2008/04/25 20:39:11 joerg Exp $
#

DISTNAME=		scapy-1.0.5
CATEGORIES=		net
MASTER_SITES=		http://www.secdev.org/projects/scapy/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.secdev.org/projects/scapy/
COMMENT=		Interactive packet manipulation program

NO_BUILD=			yes
PYTHON_VERSIONS_ACCEPTED=	25 24
PYTHON_PATCH_SCRIPTS=		scapy.py

.include "options.mk"

CONF_FILES=	${PREFIX}/share/examples/scapy/ethertypes \
		${PKG_SYSCONFDIR}/ethertypes

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	scapy.py
SUBST_SED.config=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.config=	Fixing paths.

post-extract:
	${CP} ${FILESDIR}/ethertypes ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/scapy
	${INSTALL_DATA} ${WRKSRC}/ethertypes ${PREFIX}/share/examples/scapy/
	${INSTALL_SCRIPT} ${WRKSRC}/scapy.py ${PREFIX}/bin/scapy
	${INSTALL_MAN} ${WRKSRC}/scapy.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../net/py-libpcap/buildlink3.mk"
.include "../../net/py-libdnet/buildlink3.mk"
.include "../../devel/py-readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
