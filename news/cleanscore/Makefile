# $NetBSD: Makefile,v 1.1.1.1 2007/10/12 12:30:47 is Exp $
#

DISTNAME=		cleanscore-0.9.8.1
CATEGORIES=		news
MASTER_SITES=		http://slrn.sourceforge.net/cleanscore/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://slrn.sourceforge.net/cleanscore/
COMMENT=		Clean SLRN's score file

USE_TOOLS=		perl
REPLACE_PERL=		cleanscore

NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cleanscore ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cleanscore
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cleanscore

.include "../../mk/bsd.pkg.mk"
