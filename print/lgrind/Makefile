# $NetBSD: Makefile,v 1.25 2005/12/05 20:50:53 rillig Exp $

DISTNAME=	lgrind
PKGNAME=	lgrind-3.5
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Source pretty printer for LaTeX

WRKSRC=		${WRKDIR}/lgrind/source
NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
NO_CONFIGURE=	yes
TEX_ACCEPTED=	teTeX1 teTeX2 teTeX3

.include "../../mk/x11.buildlink3.mk"

MAKE_ENV+=	PKG_TEXMFPREFIX=${PKG_TEXMFPREFIX:Q}

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
	-mkdir ${PKG_LOCALTEXMFPREFIX}/tex/latex/lgrind
	-mkdir ${PKG_LOCALTEXMFPREFIX}/doc/latex/lgrind

post-install:
	${PREFIX}/bin/texconfig rehash

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
