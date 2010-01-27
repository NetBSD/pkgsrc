# $NetBSD: Makefile,v 1.11 2010/01/27 16:41:59 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ucs
NO_CONFIGURE=	yes
NO_BUILD=	yes

UCSFILES=	ucs.sty utf8x.def ucsencs.def
UCSDIR=		${PKG_LOCALTEXMFPREFIX}/tex/latex/ucs

.include "../../print/teTeX/module.mk"

INSTALLATION_DIRS+=	${UCSDIR}/data ${UCSDIR}/contrib

do-install:
.for f in ${UCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${UCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/data/* ${DESTDIR}${UCSDIR}/data/
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${DESTDIR}${UCSDIR}/contrib/

.include "../../mk/bsd.pkg.mk"
