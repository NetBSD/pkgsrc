# $NetBSD: Makefile,v 1.3 2005/11/09 23:04:41 minskim Exp $
#

DISTNAME=	unicode
PKGNAME=	tex-ucs-20041710
CATEGORIES=	print
MASTER_SITES=	http://www.unruh.de/DniQ/latex/unicode/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.unruh.de/DniQ/latex/unicode/
COMMENT=	LaTeX UTF-8 support

WRKSRC=		${WRKDIR}/ucs
NO_CONFIGURE=	yes
NO_BUILD=	yes

UCSFILES=	ucs.sty utf8x.def ucsencs.def
UCSDIR=		${PKG_LOCALTEXMFPREFIX}/tex/latex/ucs

do-install:
	${INSTALL_DATA_DIR} ${UCSDIR}
	(cd ${WRKSRC} && \
	 for f in ${UCSFILES}; do \
	 ${INSTALL_DATA} $$f ${UCSDIR};  \
	 done)
	${CP} -r ${WRKSRC}/data ${UCSDIR}

post-install:
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
