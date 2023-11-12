# $NetBSD: Makefile,v 1.60 2023/11/12 13:20:57 wiz Exp $
#

DISTNAME=	cvsgraph-1.7.2
PKGREVISION=	5
CATEGORIES=	devel scm
MASTER_SITES=	https://www.vagrearg.org/cvsgraph/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.vagrearg.org/content/cvsgraph
COMMENT=	Graphically represents CVS/RCS branches and file revisions
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

USE_TOOLS+=		bison lex pkg-config
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/cvsgraph.conf ${PKG_SYSCONFDIR}/cvsgraph.conf
PLIST_SUBST+=	PKGBASE=${PKGBASE:Q}

BUILD_TARGET=	cvsgraph

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

CHECK_PORTABILITY_SKIP=	cvsgraph.conf.5.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsgraph ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${DOCDIR}

	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${DESTDIR}${EGDIR}

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
