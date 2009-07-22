# $NetBSD: Makefile,v 1.10 2009/07/22 09:01:45 wiz Exp $
#

DISTNAME=	unicode
PKGNAME=	tex-ucs-20041710
PKGREVISION=	4
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
.for f in ${UCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${UCSDIR}
.endfor
	${INSTALL_DATA_DIR} ${UCSDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${UCSDIR}/data/
	${INSTALL_DATA_DIR} ${UCSDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${UCSDIR}/contrib/

.include "../../mk/bsd.pkg.mk"
