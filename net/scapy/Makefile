# $NetBSD: Makefile,v 1.8 2010/02/10 19:17:43 joerg Exp $
#

DISTNAME=		scapy-2.0.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.secdev.org/projects/scapy/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.secdev.org/projects/scapy/
COMMENT=		Interactive packet manipulation program

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=			yes
NO_BUILD=			yes
PYTHON_VERSIONS_ACCEPTED=	26 25

.include "options.mk"

CONF_FILES=	${PREFIX}/share/examples/scapy/ethertypes \
		${PKG_SYSCONFDIR}/ethertypes

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	scapy/data.py
SUBST_SED.config=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.config=	Fixing paths.

post-extract:
	${CP} ${FILESDIR}/ethertypes ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/scapy
	${INSTALL_DATA} ${WRKSRC}/ethertypes ${DESTDIR}${PREFIX}/share/examples/scapy/


.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../net/py-libpcap/buildlink3.mk"
.include "../../net/py-libdnet/buildlink3.mk"
.include "../../devel/py-readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
