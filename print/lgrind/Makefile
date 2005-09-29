# $NetBSD: Makefile,v 1.22 2005/09/29 14:21:08 tonio Exp $

DISTNAME=	lgrind
PKGNAME=	lgrind-3.5
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Source pretty printer for LaTeX

DEPENDS+=	teTeX-bin>=1.0:../../print/teTeX-bin

WRKSRC=		${WRKDIR}/lgrind/source
NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
NO_CONFIGURE=	yes

.include "../../mk/x11.buildlink3.mk"

pre-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile-prepatch
	${SED} -e '/Id/s|\$$||g' ${WRKSRC}/Makefile-prepatch > ${WRKSRC}/Makefile

pre-build:
	(cd ${WRKSRC}/.. ; ${PREFIX}/bin/latex lgrind.ins)
	(cd ${WRKSRC}/.. ; ${PREFIX}/bin/latex lgrind.dtx)
	${MV} ${WRKSRC}/lgrind.1 ${WRKSRC}/lgrind.1.bak
	${MV} ${WRKSRC}/lgrindef.5 ${WRKSRC}/lgrindef.5.bak
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${WRKSRC}/lgrind.1.bak > ${WRKSRC}/lgrind.1
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${WRKSRC}/lgrindef.5.bak > ${WRKSRC}/lgrindef.5

pre-install:
	-mkdir ${PREFIX}/share/texmf/tex/latex/lgrind
	-mkdir ${PREFIX}/share/texmf/doc/latex/lgrind

post-install:
	${PREFIX}/bin/texconfig rehash

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
