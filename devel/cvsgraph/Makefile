# $NetBSD: Makefile,v 1.1.1.1 2001/12/09 14:25:00 mjl Exp $
#

DISTNAME=		cvsgraph-1.1.3
CATEGORIES=		devel
MASTER_SITES=	http://www.akhphd.au.dk/~bertho/cvsgraph/release/

MAINTAINER=		schmonz+netbsd@schmonz.com
HOMEPAGE=		http://www.akhphd.au.dk/~bertho/cvsgraph/
COMMENT=		graphically represents CVS/RCS branches and file revisions

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/cvsgraph.conf ${PKG_SYSCONFDIR}/cvsgraph.conf
PLIST_SUBST+=		PKGBASE=${PKGBASE}
FILES_SUBST=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

ALL_TARGET=		cvsgraph

pre-install:
	cd ${WRKSRC}; ${SED} ${FILES_SUBST_SED} cvsgraph.1 > cvsgraph.1.nb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsgraph ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1.nb ${PREFIX}/man/man1/cvsgraph.1
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cvsgraph
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/LICENCE ${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
