# $NetBSD: Makefile,v 1.4 2007/02/22 19:27:05 wiz Exp $
#

DISTNAME=		psjoin
PKGNAME=		psjoin-0.3
CATEGORIES=		print
MASTER_SITES=		http://homepage3.nifty.com/tsato/tools/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://homepage3.nifty.com/tsato/tools/psjoin.html
COMMENT=		Concatenate PostScript files

DIST_SUBDIR=		${PKGNAME_NOREV}
NO_BUILD=		yes
REPLACE_PERL=		psjoin
USE_TOOLS+=		perl:run
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/psjoin ${PREFIX}/bin/psjoin

.include "../../mk/bsd.pkg.mk"
