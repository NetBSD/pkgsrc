# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:32 jlam Exp $

DISTNAME=	teTeX-texmfsrc-1.0.1
PKGNAME=	teTeX-sharesrc-1.0.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX

DEPENDS+=	teTeX-share-1.0.[2-9]*:../../print/teTeX1-share

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
NO_BUILDINK=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
USE_TOOLS+=	patch

FILESDIR=	${.CURDIR}/../../print/teTeX1-share/files
EXTRA_PATCH=	${FILESDIR}/latex.ltx.diff

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	extract_file=${_DISTDIR:Q}/${DISTFILES:Q};			\
	cd ${PREFIX}/share/texmf; ${EXTRACT_CMD}

post-install:
	@cd ${PREFIX}/share/texmf/source/latex/base && \
	  ${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${EXTRA_PATCH} && \
	  ${RM} latex.ltx.orig

.include "../../mk/bsd.pkg.mk"
