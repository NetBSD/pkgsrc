# $NetBSD: Makefile,v 1.1.1.1 2003/02/23 04:59:37 kei Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp

DISTNAME=	tetex-texmfsrc-2.0.1
PKGNAME=	teTeX2-sharesrc-2.0.1
PKGREVISION=	# empty
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX, version 2

DEPENDS+=	teTeX2-share>=2.0.1:../teTeX2-share

DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}
USE_BUILDINK2=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
.if defined(EXTRACT_USING_PAX)
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -r
.else
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${GTAR} -xpf -
.endif

.include "../../mk/bsd.pkg.mk"
