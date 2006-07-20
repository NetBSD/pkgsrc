# $NetBSD: Makefile,v 1.30 2006/07/20 05:24:07 rillig Exp $

DISTNAME=	tetex-texmfsrc-2.0.2
PKGNAME=	teTeX-sharesrc-2.0.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX, version 2

CONFLICTS+=	teTeX2-sharesrc-[0-9]*

DEPENDS+=	teTeX-share>=2.0.2:../../print/teTeX-share

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
NO_BUILD=	yes
INSTALLATION_DIRS=	share/texmf

REPLACE_PERL+=	source/latex/t2/enc-maps/make-enc.pl
REPLACE_PERL+=	source/latex/koma-script/genindex.pl
# Left out because the above files are seldomly used.
#USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"

do-install:
	cd ${WRKSRC} && ${PAX} -wr LICENSE.* source ${PREFIX}/share/texmf

.include "../../mk/bsd.pkg.mk"
