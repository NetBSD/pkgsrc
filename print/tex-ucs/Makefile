# $NetBSD: Makefile,v 1.1.1.1 2005/08/09 18:33:38 drochner Exp $
#

DISTNAME=		unicode
PKGNAME=		tex-ucs-20041710
CATEGORIES=		print
MASTER_SITES=		http://www.unruh.de/DniQ/latex/unicode/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.unruh.de/DniQ/latex/unicode/
COMMENT=		LaTeX UTF-8 support

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

WRKSRC=		${WRKDIR}/ucs
NO_CONFIGURE=	yes
NO_BUILD=	yes

UCSFILES=	ucs.sty utf8x.def ucsencs.def
UCSDIR=		${PREFIX}/share/texmf/tex/latex/ucs

do-install:
	${INSTALL_DATA_DIR} ${UCSDIR}
	(cd ${WRKSRC} && \
	 for f in ${UCSFILES}; do \
	 ${INSTALL_DATA} $$f ${UCSDIR};  \
	 done)
	${CP} -r ${WRKSRC}/data ${UCSDIR}

post-install:
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/bsd.pkg.mk"
