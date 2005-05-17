# $NetBSD: Makefile,v 1.6 2005/05/17 22:00:13 jlam Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	tetex-texmfsrc-3.0
PKGNAME=	${DISTNAME:S/tetex/teTeX/}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX

DEPENDS+=	teTeX-texmf>=3.0:../teTeX3-texmf

CONFLICTS+=	teTeX-sharesrc-[0-9]*

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
