# $NetBSD: Makefile,v 1.1.1.1 2003/12/24 12:56:11 jmmv Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	teTeX-texmfsrc-1.0.1
PKGNAME=	teTeX-sharesrc-1.0.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX

DEPENDS+=	teTeX-share-1.0.[2-9]*:../teTeX1-share

DIST_SUBDIR=	teTeX
USE_BUILDINK2=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

FILESDIR=	${.CURDIR}/../../print/teTeX1-share/files
EXTRA_PATCH=	${FILESDIR}/latex.ltx.diff

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -O -r

post-install:
	@cd ${PREFIX}/share/texmf/source/latex/base && \
	  ${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${EXTRA_PATCH} && \
	  ${RM} latex.ltx.orig

.include "../../mk/bsd.pkg.mk"
