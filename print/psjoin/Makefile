# $NetBSD: Makefile,v 1.18 2022/06/28 11:35:30 wiz Exp $
#

DISTNAME=		psjoin
PKGNAME=		psjoin-0.3
PKGREVISION=		10
CATEGORIES=		print
MASTER_SITES=		http://t-sato.in.coocan.jp/tools/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://t-sato.in.coocan.jp/tools/psjoin.html
COMMENT=		Concatenate PostScript files

DIST_SUBDIR=		${PKGNAME_NOREV}
NO_BUILD=		yes
REPLACE_PERL=		psjoin
USE_TOOLS+=		perl:run
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/psjoin ${DESTDIR}${PREFIX}/bin/psjoin

.include "../../mk/bsd.pkg.mk"
