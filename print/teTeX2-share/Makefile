# $NetBSD: Makefile,v 1.4 2003/04/10 20:10:19 grant Exp $

DISTNAME=	tetex-texmf-2.0.2
PKGNAME=	teTeX2-share-2.0.2
PKGREVISION=	# empty
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX, version 2

CONFLICTS+=	teTeX-share-[0-9]*

DIST_SUBDIR=	teTeX
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
.if defined(EXTRACT_USING_PAX)
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -O -cr `${CAT} ${FILESDIR}/exclude`
.else
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${GTAR} -X ${FILESDIR}/exclude -xpf -
.endif

.include "../../mk/bsd.pkg.mk"
