# $NetBSD: Makefile,v 1.2 2009/02/17 20:59:56 minskim Exp $
# TeX Live Revision 12157

DISTNAME=	bin-tetex
PKGNAME=	tex-${DISTNAME}-3.0.12157
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Supplementary files for updmap

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/texmf.mk"

post-extract:
	${RM} -f ${WRKSRC}/texmf/web2c/updmap.cfg
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
