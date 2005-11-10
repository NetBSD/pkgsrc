# $NetBSD: Makefile,v 1.5 2005/11/10 05:22:00 minskim Exp $
#

DISTNAME=	IEEEtran
PKGNAME=	tex-IEEEtran-1.6c
CATEGORIES=	print
MASTER_SITES=	http://www.ieee.org/portal/cms_docs/pubs/transactions/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ieee.org/organizations/pubs/transactions/stylesheets.htm
COMMENT=	LaTeX class for IEEE journals and conferences

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran
	${INSTALL_DATA} ${WRKSRC}/* ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran

post-install:
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
