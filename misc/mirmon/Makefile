# $NetBSD: Makefile,v 1.1.1.1 2006/07/21 13:15:22 heinz Exp $
#

DISTNAME=		mirmon-1.36
CATEGORIES=		misc
MASTER_SITES=		http://www.cs.uu.nl/people/henkp/mirmon/src/

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.cs.uu.nl/people/henkp/mirmon/
COMMENT=		Monitor the state of mirror servers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_PERL+=		mirmon
USE_TOOLS+=		perl:run pod2man
USE_LANGUAGES=		# empty

EG_DIR=			${PREFIX}/share/examples/mirmon
MIRMONDIR=		${PREFIX}/share/mirmon

SUBST_CLASSES+=		mirmon1 mirmon2

SUBST_STAGE.mirmon1=	pre-configure
SUBST_FILES.mirmon1=	mirmon
SUBST_SED.mirmon1+=	-e s!/etc/!${PKG_SYSCONFDIR}/!g
SUBST_SED.mirmon1+=	-e s!/sw/!${LOCALBASE}/!g

SUBST_STAGE.mirmon2=	pre-configure
SUBST_FILES.mirmon2=	${WRKDIR}/mirmon.conf
SUBST_SED.mirmon2+=	-e s!@@MIRMONDIR@@!${MIRMONDIR}!g

post-extract:
	${CP} ${FILESDIR}/mirmon.conf ${WRKDIR}

do-build:
	cd ${WRKSRC} && ${POD2MAN} mirmon > ${WRKDIR}/mirmon.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mirmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/mirmon.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${EG_DIR}
	${INSTALL_DATA} ${WRKDIR}/mirmon.conf ${EG_DIR}
	${INSTALL_DATA_DIR} ${MIRMONDIR}
	${INSTALL_DATA} ${WRKSRC}/countries.list ${MIRMONDIR}
	${INSTALL_DATA_DIR} ${MIRMONDIR}/icons
	cd ${WRKSRC}/icons && \
	 for f in *; do ${INSTALL_DATA} $${f} ${MIRMONDIR}/icons; done

.include "../../mk/bsd.pkg.mk"
