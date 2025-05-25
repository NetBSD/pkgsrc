# $NetBSD: Makefile,v 1.61 2025/05/25 15:04:07 vins Exp $

DISTNAME=	exmh-2.9.0
CATEGORIES=	mail tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=exmh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.beedub.com/exmh/
COMMENT=	X11/TK based mail reader front end to MH
LICENSE=	2-clause-bsd

DEPENDS+=	nmh>=1.3:../../mail/nmh
DEPENDS+=	metamail>=2.7:../../mail/metamail
DEPENDS+=	mime-types-[0-9]*:../../misc/mime-types
DEPENDS+=	tcl-expect-[0-9]*:../../lang/tcl-expect

USE_TOOLS+=	pax tclsh wish:run

.include "../../mk/bsd.prefs.mk"

DIST_SUBDIR=	${PKGNAME_NOREV}

EXMH_LIBDIR=	${PREFIX}/lib/${PKGNAME_NOREV}
EXMH_SCRIPTS=	exmh exmh-async exmh-bg exmh-strip exmhcomp \
		ftp.expect inc.expect

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	exmhcomp lib/bitmaps/bitmaps.defaults
SUBST_SED.paths+=	-e "s:/usr/local:${PREFIX}:g"
SUBST_SED.paths+=	-e "s:/usr/bin/wish:${TOOLS_PATH.wish}:g"
SUBST_SED.paths+=	-e "s:/usr/lib/exmh:${EXMH_LIBDIR}/bitmaps:g"

MAKE_ENV+=	PREFIX=${PREFIX} TCLSH=${TCLSH:Q} WISH=${WISH:Q} \
		WRKSRC=${WRKSRC} FILESDIR=${FILESDIR}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

do-build:
	${RUN}cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${SH} ${FILESDIR}/build

pre-install:
	${RUN}${FIND} ${WRKSRC}/lib -type f \
		\( -name "*.orig" -o -name "*.old" \) -delete

do-install:
	${INSTALL_MAN} ${WRKSRC}/exmh.l \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/exmh.1
	for i in ${EXMH_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin; \
	done
	${RUN}cd ${WRKSRC}/lib && ${PAX} -rw -pm . ${DESTDIR}${EXMH_LIBDIR}
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
