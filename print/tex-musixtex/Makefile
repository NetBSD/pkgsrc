# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:31 jlam Exp $
#

DISTNAME=	musixtex-112
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/musixtex/taupin/}
DISTFILES=	musixtex-T112.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	http://icking-music-archive.sunsite.dk/
COMMENT=	TeX macros to typeset music

DEPENDS+=       teTeX>=2:../../print/teTeX

WRKSRC=		${WRKDIR}/musixtex-T112
NO_CONFIGURE=	yes

TEXMF=		${LOCALBASE}/share/texmf
TEXMF_CNF=	${LOCALBASE}/share/texmf/web2c/texmf.cnf

.include "../../mk/bsd.prefs.mk"
.if exists(${LOCALBASE}/bin/initex)
INITEX= 	initex		# teTeX2
.else
INITEX= 	tex -ini	# teTeX3
.endif

INSTALLATION_DIRS=	bin man/man1

do-build:
	@${ECHO} "======> Building musixtex.fmt"
	${CP} -f ${WRKSRC}/system/dos/musixtex.ins \
		${WRKSRC}/tex
	cd ${WRKSRC}/tex ; \
		(TEXFONTS=${WRKSRC}/tfm ${INITEX} '&tex musixtex.ins \dump')
	@${ECHO} "======> Building musixflx executable"
	cd ${WRKSRC}/system/c-source; ${CC} -o musixflx musixflx.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/doc/musixtex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/tfm/musixtex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/source/musixtex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/musixtex

	${INSTALL_DATA} ${WRKSRC}/doc/* \
		${PREFIX}/share/texmf/doc/musixtex

	${INSTALL_DATA} ${WRKSRC}/tex/musixtex.fmt \
		${PREFIX}/share/texmf/web2c

	${INSTALL_DATA} ${WRKSRC}/tex/* \
		${PREFIX}/share/texmf/tex/latex/musixtex

	${INSTALL_DATA} ${WRKSRC}/mf/*.mf \
		${PREFIX}/share/texmf/fonts/source/musixtex

	${INSTALL_DATA} ${WRKSRC}/tfm/*.tfm \
		${PREFIX}/share/texmf/fonts/tfm/musixtex

	${INSTALL_PROGRAM} ${WRKSRC}/system/c-source/musixflx \
		${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/system/c-source/musixflx.1 \
		${PREFIX}/man/man1

.if exists(${LOCALBASE}/bin/virtex)
	cd ${PREFIX}/bin ; ${LN} -sf virtex musixtex	# teTeX2
.else
	cd ${PREFIX}/bin ; ${LN} -sf tex musixtex	# teTeX3
.endif

	${LOCALBASE}/bin/texconfig rehash

post-install:
	@${ECHO} "======> Building musixdoc.ps"
	cd ${PREFIX}/share/texmf/doc/musixtex ; \
		latex musixdoc ; \
		musixflx musixdoc ; \
		latex  musixdoc ; \
		makeindex musixdoc.idx ; \
		latex  musixdoc ; \
		makeindex musixdoc.idx ; \
		latex  musixdoc ; \
		dvips musixdoc.dvi -o musixdoc.ps

.include "../../mk/bsd.pkg.mk"
