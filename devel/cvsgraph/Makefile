# $NetBSD: Makefile,v 1.19 2005/06/16 06:57:45 jlam Exp $
#

DISTNAME=	cvsgraph-1.5.1
CATEGORIES=	devel
MASTER_SITES=	http://www.akhphd.au.dk/~bertho/cvsgraph/release/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.akhphd.au.dk/~bertho/cvsgraph/
COMMENT=	Graphically represents CVS/RCS branches and file revisions

USE_TOOLS+=		lex
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/cvsgraph.conf ${PKG_SYSCONFDIR}/cvsgraph.conf
PLIST_SUBST+=	PKGBASE=${PKGBASE}

BUILD_TARGET=	cvsgraph

SUBST_CLASSES=		man
SUBST_STAGE.man=	pre-install
SUBST_FILES.man= 	cvsgraph.1
SUBST_SED.man=		-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.man=	"Fixing man page paths."

INSTALLATION_DIRS=	bin man/man1 man/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsgraph ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 ${PREFIX}/man/man5

	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}

	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${EGDIR}

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
