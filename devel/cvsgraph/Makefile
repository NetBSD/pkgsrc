# $NetBSD: Makefile,v 1.37 2011/11/01 06:00:54 sbd Exp $
#

DISTNAME=	cvsgraph-1.6.1
PKGREVISION=	5
CATEGORIES=	devel scm
MASTER_SITES=	http://www.akhphd.au.dk/~bertho/cvsgraph/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.akhphd.au.dk/~bertho/cvsgraph/
COMMENT=	Graphically represents CVS/RCS branches and file revisions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		bison lex
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/cvsgraph.conf ${PKG_SYSCONFDIR}/cvsgraph.conf
PLIST_SUBST+=	PKGBASE=${PKGBASE:Q}

BUILD_TARGET=	cvsgraph

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-install
SUBST_FILES.man=	cvsgraph.1
SUBST_SED.man=		-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.man=	Fixing man page paths.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsgraph ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}

	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${DESTDIR}${EGDIR}

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
