# $NetBSD: Makefile,v 1.6 2005/11/13 04:03:11 minskim Exp $
#

DISTNAME=	IEEEtran
PKGNAME=	tex-IEEEtran-1.6c
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.ieee.org/portal/cms_docs/pubs/transactions/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ieee.org/organizations/pubs/transactions/stylesheets.htm
COMMENT=	LaTeX class for IEEE journals and conferences

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran
	${INSTALL_DATA} ${WRKSRC}/* ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran

.include "../../mk/bsd.pkg.mk"
