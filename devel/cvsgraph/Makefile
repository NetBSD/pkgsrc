# $NetBSD: Makefile,v 1.5 2002/09/21 08:27:25 jlam Exp $
#

DISTNAME=	cvsgraph-1.2.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.akhphd.au.dk/~bertho/cvsgraph/release/

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://www.akhphd.au.dk/~bertho/cvsgraph/
COMMENT=	graphically represents CVS/RCS branches and file revisions

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/cvsgraph.conf ${PKG_SYSCONFDIR}/cvsgraph.conf
PLIST_SUBST+=	PKGBASE=${PKGBASE}
FILES_SUBST=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

ALL_TARGET=	cvsgraph

pre-install:
	cd ${WRKSRC}; ${SED} ${FILES_SUBST_SED} cvsgraph.1 > cvsgraph.1.nb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsgraph ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1.nb ${PREFIX}/man/man1/cvsgraph.1
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 ${PREFIX}/man/man5

	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}

	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${EGDIR}

.include "../../graphics/gd/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
