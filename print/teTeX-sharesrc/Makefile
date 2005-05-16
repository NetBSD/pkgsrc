# $NetBSD: Makefile,v 1.24 2005/05/16 01:15:33 jlam Exp $

DISTNAME=	tetex-texmfsrc-2.0.2
PKGNAME=	teTeX-sharesrc-2.0.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX, version 2

CONFLICTS+=	teTeX2-sharesrc-[0-9]*

DEPENDS+=	teTeX-share>=2.0.2:../teTeX-share

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

.if !defined(EXTRACT_USING_PAX)
PKGSRC_USE_TOOLS+=	gtar
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
.if defined(EXTRACT_USING_PAX)
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -O -r
.else
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${GTAR} -xpf -
.endif

.include "../../mk/bsd.pkg.mk"
