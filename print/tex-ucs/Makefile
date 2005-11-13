# $NetBSD: Makefile,v 1.5 2005/11/13 04:14:31 minskim Exp $
#

DISTNAME=	unicode
PKGNAME=	tex-ucs-20041710
PKGREVISION=	1
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

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${UCSDIR}
	(cd ${WRKSRC} && \
	 for f in ${UCSFILES}; do \
	 ${INSTALL_DATA} $$f ${UCSDIR};  \
	 done)
	${CP} -r ${WRKSRC}/data ${UCSDIR}

.include "../../mk/bsd.pkg.mk"
