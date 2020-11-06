# $NetBSD: Makefile,v 1.6 2020/11/06 18:04:27 maya Exp $

VERSION=	0.83
PKGNAME=	ubuntu-fonts-${VERSION}
CATEGORIES=	fonts
DISTNAME=	ubuntu-font-family-${VERSION}
EXTRACT_SUFX=	.zip
MASTER_SITES=	http://font.ubuntu.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://font.ubuntu.com/
COMMENT=	TrueType font family from Ubuntu
LICENSE=	ubuntu-font-license

NO_CONFIGURE=	yes
NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}

INSTALL_DOCS=	CONTRIBUTING.txt		\
		FONTLOG.txt			\
		LICENCE-FAQ.txt			\
		LICENCE.txt			\
		README.txt			\
		TRADEMARKS.txt			\
		copyright.txt

do-install:
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
