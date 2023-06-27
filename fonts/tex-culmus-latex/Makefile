#	$NetBSD: Makefile,v 1.1 2023/06/27 10:52:47 riastradh Exp $

DISTNAME=	culmus-latex-0.7
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ivritex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.guyrutenberg.com/culmus-latex/
COMMENT=	Hebrew font family set for TeX
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax

NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist
INSTALLATION_DIRS+=	${PREFIX}/share/examples/culmus

do-install:
	cd ${WRKSRC}/usr/share/texmf && \
	${PAX} -wr . ${DESTDIR}${PREFIX}/share/texmf-dist
	cd ${WRKSRC}/examples && \
	${RM} -rf .svn */.svn && \
	${PAX} -wr . ${DESTDIR}${PREFIX}/share/examples/culmus

TEX_MAP_FILES+=	culmus.map

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
