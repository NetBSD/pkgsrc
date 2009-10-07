# $NetBSD: Makefile,v 1.25 2009/10/07 17:34:53 joerg Exp $
#

DISTNAME=	musixtex-112
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/musixtex/taupin/}
DISTFILES=	musixtex-T112.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	http://icking-music-archive.org/
COMMENT=	TeX macros to typeset music

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

TEX_ACCEPTED=	teTeX3

WRKSRC=		${WRKDIR}/musixtex-T112
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 texmf-local/web2c \
	${PKG_LOCALTEXMFPREFIX}/doc/musixtex \
	${PKG_LOCALTEXMFPREFIX}/fonts/tfm/musixtex \
	${PKG_LOCALTEXMFPREFIX}/fonts/source/musixtex \
	${PKG_LOCALTEXMFPREFIX}/tex/latex/musixtex \
	${PKG_LOCALTEXMFPREFIX}/web2c

.include "../../print/teTeX/module.mk"

do-build:
	@${ECHO} "======> Building musixtex.fmt"
	${CP} -f ${WRKSRC}/system/dos/musixtex.ins \
		${WRKSRC}/tex
	cd ${WRKSRC}/tex ; \
		(TEXFONTS=${WRKSRC}/tfm tex -ini '&tex musixtex.ins \dump')
	@${ECHO} "======> Building musixflx executable"
	cd ${WRKSRC}/system/c-source; ${CC} -o musixflx musixflx.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/musixtex
	${INSTALL_DATA} ${WRKSRC}/tex/musixtex.fmt \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/web2c
	${INSTALL_DATA} ${WRKSRC}/tex/* \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/musixtex
	${INSTALL_DATA} ${WRKSRC}/mf/*.mf \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/source/musixtex
	${INSTALL_DATA} ${WRKSRC}/tfm/*.tfm \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/tfm/musixtex
	${INSTALL_PROGRAM} ${WRKSRC}/system/c-source/musixflx \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/system/c-source/musixflx.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -s tex ${DESTDIR}${PREFIX}/bin/musixtex

	${LOCALBASE}/bin/mktexlsr ${PKG_LOCALTEXMFPREFIX}

post-install:
	@${ECHO} "======> Building musixdoc.ps"
	cd ${PKG_LOCALTEXMFPREFIX}/doc/musixtex ; \
		latex musixdoc ; \
		musixflx musixdoc ; \
		latex  musixdoc ; \
		makeindex musixdoc.idx ; \
		latex  musixdoc ; \
		makeindex musixdoc.idx ; \
		latex  musixdoc ; \
		dvips musixdoc.dvi -o musixdoc.ps

.include "../../mk/bsd.pkg.mk"
