# $NetBSD: Makefile,v 1.8 2005/11/13 04:19:00 minskim Exp $
#

DISTNAME=	prosper-1.00.4
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prosper/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} PPRblends.sty.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://prosper.sourceforge.net/
COMMENT=	LaTeX class for writing transparencies

WRKSRC=		${WRKDIR}/prosper
NO_CONFIGURE=	yes
NO_BUILD=	yes

TEXMF=		${PKG_LOCALTEXMFPREFIX}
PROSPERDIR=	${TEXMF}/tex/latex/misc/prosper

DOCS=		AUTHORS ChangeLog FAQ INSTALL NEWS README TODO \
		TROUBLESHOOTINGS
DOCDIR=		${LOCALBASE}/share/doc/tex-prosper
EGDIR=		${LOCALBASE}/share/examples/tex-prosper

.include "../../print/teTeX/module.mk"

post-extract:
	${MV} ${WRKDIR}/PPRblends.sty ${WRKSRC}/contrib
	${MV} ${WRKSRC}/doc/doc-examples ${WRKSRC}/examples
	${FIND} ${WRKSRC} -name CVS -print0 | ${XARGS} -0 ${RM} -rf

do-install:
	${INSTALL_DATA_DIR} ${PROSPERDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rw -pp -pm *.sty *.cls img contrib designer \
		${PROSPERDIR}
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${DOCDIR}
	cd ${WRKSRC}/examples && ${PAX} -rw -pp -pm . ${EGDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
