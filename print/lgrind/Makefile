# $NetBSD: Makefile,v 1.29 2006/08/10 03:21:40 minskim Exp $

DISTNAME=	lgrind
PKGNAME=	lgrind-3.5
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Source pretty printer for LaTeX

WRKSRC=		${WRKDIR}/lgrind/source
NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
NO_CONFIGURE=	yes
USE_DIRS+=	texmf-1.0
TEX_ACCEPTED=	teTeX3

.include "../../mk/x11.buildlink3.mk"
.include "../../print/teTeX/module.mk"

MAKE_ENV+=	PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX:Q}

pre-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile-prepatch
	${SED} -e '/Id/s|\$$||g' ${WRKSRC}/Makefile-prepatch > ${WRKSRC}/Makefile

pre-build:
	(cd ${WRKSRC}/.. ; ${PREFIX}/bin/latex lgrind.ins)
	(cd ${WRKSRC}/.. ; ${PREFIX}/bin/latex lgrind.dtx)
	${MV} ${WRKSRC}/lgrind.1 ${WRKSRC}/lgrind.1.bak
	${MV} ${WRKSRC}/lgrindef.5 ${WRKSRC}/lgrindef.5.bak
	${SED}	-e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@LOCALTEXMFPREFIX@,${PKG_LOCALTEXMFPREFIX},g' \
		< ${WRKSRC}/lgrind.1.bak > ${WRKSRC}/lgrind.1
	${SED} -e 's,@LOCALTEXMFPREFIX@,${PKG_LOCALTEXMFPREFIX},g' \
		< ${WRKSRC}/lgrindef.5.bak > ${WRKSRC}/lgrindef.5

pre-install:
	-mkdir ${PKG_LOCALTEXMFPREFIX}/tex/latex/lgrind
	-mkdir ${PKG_LOCALTEXMFPREFIX}/doc/latex/lgrind

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
