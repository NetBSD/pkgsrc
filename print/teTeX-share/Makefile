# $NetBSD: Makefile,v 1.16 2002/10/31 03:08:09 wiz Exp $
#

DISTNAME=	teTeX-texmf-1.0.2
PKGNAME=	teTeX-share-1.0.2
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

EXTRA_PATCH=	${FILESDIR}/latex.ltx.diff

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -cr `${CAT} ${FILESDIR}/exclude`

post-install:
	@cd ${PREFIX}/share/texmf/tex/latex/base && \
	  ${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${EXTRA_PATCH} && \
	  ${RM} latex.ltx.orig
	${CP} ${FILESDIR}/dvipdfm.def ${PREFIX}/share/texmf/tex/latex/graphics

.include "../../mk/bsd.pkg.mk"
