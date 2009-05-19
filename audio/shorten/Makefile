# $NetBSD: Makefile,v 1.13 2009/05/19 08:59:04 wiz Exp $
#

DISTNAME=	shorten-3.6.1
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shorten/dist/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.etree.org/shnutils/shorten/
COMMENT=	Lossless audio compressor
LICENSE=	shorten-license

GNU_CONFIGURE=	YES
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	share/doc/shorten

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.tex ${DESTDIR}${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.ps ${DESTDIR}${PREFIX}/share/doc/shorten

.include "../../mk/bsd.pkg.mk"
