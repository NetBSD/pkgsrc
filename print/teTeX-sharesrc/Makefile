# $NetBSD: Makefile,v 1.10 2001/11/29 01:12:45 hubertf Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	teTeX-texmfsrc-1.0.1
PKGNAME=	teTeX-sharesrc-1.0.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/1.0/distrib/sources/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX

DEPENDS+=	teTeX-share>=1.0.2nb1:../teTeX-share

DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

FILESDIR=	${.CURDIR}/../../print/teTeX-share/files
EXTRA_PATCH=	${FILESDIR}/latex.ltx.diff

do-install:
	@${ECHO} ""
	@${ECHO} "Extracting ${DISTFILES} to ${PREFIX}/share/texmf/source"
	@${ECHO} "  Get yourself a shower and a mug of coffee, this will take long!"
	@${ECHO} ""
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	${GTAR} -plzx \
		-C ${PREFIX}/share/texmf \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@cd ${PREFIX}/share/texmf/source/latex/base && \
	  ${PATCH} < ${EXTRA_PATCH} && \
	  ${RM} latex.ltx.orig

.include "../../mk/bsd.pkg.mk"
