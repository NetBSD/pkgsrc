# $NetBSD: Makefile,v 1.27 2005/05/17 22:00:13 jlam Exp $

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

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	extract_file=${_DISTDIR:Q}/${DISTFILES:Q};			\
	cd ${PREFIX}/share/texmf; ${EXTRACT_CMD${EXTRACT_SUFX}}

.include "../../mk/bsd.pkg.mk"
