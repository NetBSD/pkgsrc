# $NetBSD: Makefile,v 1.34 2012/10/08 13:45:41 asau Exp $

DISTNAME=	lgrind
PKGNAME=	lgrind-3.5
PKGREVISION=	9
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Source pretty printer for LaTeX

BUILD_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

WRKSRC=		${WRKDIR}/lgrind
NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
NO_CONFIGURE=	yes

EVAL_PREFIX+=	LATEX_PREFIX=tex-latex-bin
MAKE_ENV+=	PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX:Q}

.include "../../print/kpathsea/texmf.mk"

INSTALLATION_DIRS=	bin man/man1 man/man5 \
			share/texmf-dist/doc/latex/lgrind \
			share/texmf-dist/tex/latex/lgrind

pre-patch:
	${MV} ${WRKSRC}/source/Makefile ${WRKSRC}/source/Makefile-prepatch
	${SED} -e '/Id/s|\$$||g' ${WRKSRC}/source/Makefile-prepatch > \
		${WRKSRC}/source/Makefile

pre-build:
	(cd ${WRKSRC} && ${LATEX_PREFIX}/bin/latex lgrind.ins)
	(cd ${WRKSRC} && ${LATEX_PREFIX}/bin/pdflatex lgrind.dtx)
	${MV} ${WRKSRC}/source/lgrind.1 ${WRKSRC}/source/lgrind.1.bak
	${MV} ${WRKSRC}/source/lgrindef.5 ${WRKSRC}/source/lgrindef.5.bak
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKSRC}/source/lgrind.1.bak > ${WRKSRC}/source/lgrind.1
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${WRKSRC}/source/lgrindef.5.bak > ${WRKSRC}/source/lgrindef.5

do-build:
	${RUN} cd ${WRKSRC}/source && \
		${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} ${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/lgrind ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/source/lgrind.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/source/lgrindef.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_DATA} ${WRKSRC}/lgrind.pdf \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/lgrind/
	${INSTALL_DATA} ${WRKSRC}/lgrindef \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/lgrind/
	${INSTALL_DATA} ${WRKSRC}/lgrind.sty \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/lgrind/

.include "../../mk/bsd.pkg.mk"
