# $NetBSD: Makefile,v 1.11 2018/08/22 09:46:09 wiz Exp $
#

DISTNAME=		cleanscore-0.9.8.1
PKGREVISION=		8
LICENSE=		gnu-gpl-v2
CATEGORIES=		news
MASTER_SITES=		http://slrn.sourceforge.net/cleanscore/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://slrn.sourceforge.net/cleanscore/
COMMENT=		Clean SLRN's score file

USE_TOOLS=		perl
REPLACE_PERL=		cleanscore

NO_BUILD=		yes

INSTALLATION_DIRS+=	bin share/doc/cleanscore

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cleanscore ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cleanscore
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/cleanscore

.include "../../mk/bsd.pkg.mk"
