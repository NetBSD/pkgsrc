# $NetBSD: Makefile,v 1.13 2002/09/21 00:46:32 jlam Exp $
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
	@${ECHO} ""
	@${ECHO} "Extracting ${DISTFILES} to ${PREFIX}/share/texmf"
	@${ECHO} ""
	@${ECHO} "  ** Get yourself a shower and a big mug of coffee,"
	@${ECHO} "  ** this will take _very_ long!"
	@${ECHO} ""
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	${GTAR} -plzx \
		-C ${PREFIX}/share/texmf \
		-X ${FILESDIR}/exclude \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@cd ${PREFIX}/share/texmf/tex/latex/base && \
	  ${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${EXTRA_PATCH} && \
	  ${RM} latex.ltx.orig
	${CP} ${FILESDIR}/dvipdfm.def ${PREFIX}/share/texmf/tex/latex/graphics

.include "../../mk/bsd.pkg.mk"
