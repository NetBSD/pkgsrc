# $NetBSD: Makefile,v 1.10 2006/07/27 00:09:06 hubertf Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	tetex-texmfsrc-3.0
PKGNAME=	${DISTNAME:S/tetex/teTeX/}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org,pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX

DEPENDS+=	teTeX-texmf>=3.0nb3:../../print/teTeX3-texmf

CONFLICTS+=	teTeX-sharesrc-[0-9]*

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

.include "../../mk/bsd.prefs.mk"

do-install:
	extract_file=${_DISTDIR:Q}/${DISTFILES:Q};			\
	cd ${PREFIX}/share/texmf-dist; ${EXTRACT_CMD}

.include "../../mk/bsd.pkg.mk"
