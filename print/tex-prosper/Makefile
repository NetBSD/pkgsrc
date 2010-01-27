# $NetBSD: Makefile,v 1.15 2010/01/27 16:35:37 joerg Exp $
#

DISTNAME=	prosper-1.00.4
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prosper/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} PPRblends.sty.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/prosper/
COMMENT=	LaTeX class for writing transparencies

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/prosper
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

TEXMF=		${PKG_LOCALTEXMFPREFIX}
PROSPERDIR=	${TEXMF}/tex/latex/prosper

DOCS=		AUTHORS ChangeLog FAQ INSTALL NEWS README TODO \
		TROUBLESHOOTINGS
DOCDIR=		${PREFIX}/share/doc/tex-prosper
EGDIR=		${PREFIX}/share/examples/tex-prosper

.include "../../print/teTeX/module.mk"

post-extract:
	${MV} ${WRKDIR}/PPRblends.sty ${WRKSRC}/contrib
	${MV} ${WRKSRC}/doc/doc-examples ${WRKSRC}/examples
	${FIND} ${WRKSRC} -name CVS -print | ${XARGS} ${RM} -rf

INSTALLATION_DIRS+=	${PROSPERDIR} ${DOCDIR} ${EGDIR}

do-install:
	cd ${WRKSRC} && pax -rw -pp -pm *.sty *.cls img contrib designer \
	    ${DESTDIR}${PROSPERDIR}
	cd ${WRKSRC}/doc && pax -rw -pp -pm . ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -rw -pp -pm . ${DESTDIR}${EGDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
