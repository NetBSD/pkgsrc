# $NetBSD: Makefile,v 1.20 2003/12/24 12:51:31 jmmv Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	tetex-texmfsrc-2.0.2
PKGNAME=	teTeX-sharesrc-2.0.2
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX, version 2

CONFLICTS+=	teTeX2-sharesrc-[0-9]*

DEPENDS+=	teTeX-share>=2.0.2:../teTeX-share

DIST_SUBDIR=	teTeX
USE_BUILDINK2=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
.if defined(EXTRACT_USING_PAX)
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -O -r
.else
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${GTAR} -xpf -
.endif

.include "../../mk/bsd.pkg.mk"
