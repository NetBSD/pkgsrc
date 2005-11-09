# $NetBSD: Makefile,v 1.8 2005/11/09 21:34:26 tonio Exp $
#

DISTNAME=	teTeX-texmf-1.0.2
PKGNAME=	teTeX-share-1.0.2
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

CONFLICTS+=	teTeX2-share-[2-9]*
CONFLICTS+=	teTeX-texmf-[0-9]*

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
USE_TOOLS+=	patch

EXTRA_PATCH=	${FILESDIR}/latex.ltx.diff

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -O -cr `${CAT} ${FILESDIR}/exclude`

post-install:
	@cd ${PREFIX}/share/texmf/tex/latex/base && \
	  ${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${EXTRA_PATCH} && \
	  ${RM} latex.ltx.orig
	${CP} ${FILESDIR}/dvipdfm.def ${PREFIX}/share/texmf/tex/latex/graphics

.include "../../mk/bsd.pkg.mk"
