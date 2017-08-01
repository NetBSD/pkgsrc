# $NetBSD: Makefile,v 1.3 2017/08/01 14:59:06 wiz Exp $
#

DISTNAME=		dadadodo-1.04
CATEGORIES=		textproc
MASTER_SITES=		https://www.jwz.org/dadadodo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.jwz.org/dadadodo/
COMMENT=		Analyse texts for word probabilities and generate random sentences
# near enough
LICENSE=		mit

INSTALLATION_DIRS=	bin share/doc/dadadodo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dadadodo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dadadodo

.include "../../mk/bsd.pkg.mk"
