# $NetBSD: Makefile,v 1.1.1.1 2009/02/08 20:40:32 minskim Exp $
# TeX Live Revision 12107

DISTNAME=	bin-kpathsea
PKGNAME=	tex-${DISTNAME}-2008.12107
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Translation tables for TeX

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/texmf.mk"

post-extract:
	${RM} -f ${WRKSRC}/texmf/web2c/mktex.opt
	${RM} -f ${WRKSRC}/texmf/web2c/mktexdir
	${RM} -f ${WRKSRC}/texmf/web2c/mktexdir.opt
	${RM} -f ${WRKSRC}/texmf/web2c/mktexnam
	${RM} -f ${WRKSRC}/texmf/web2c/mktexnam.opt
	${RM} -f ${WRKSRC}/texmf/web2c/mktexupd
	${RM} -f ${WRKSRC}/texmf/web2c/texmf.cnf
	${RM} -f ${WRKSRC}/texmf/web2c/fmtutil.cnf
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
