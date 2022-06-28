# $NetBSD: Makefile,v 1.23 2022/06/28 11:30:58 wiz Exp $
#

DISTNAME=	rip-1.07
PKGREVISION=	10
CATEGORIES=	audio perl5
MASTER_SITES=	http://rip.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rip.sourceforge.net/
COMMENT=	Command-line based audio CD ripper and encoder
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-CDDB_get>=2.23:../../audio/p5-CDDB_get
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info

NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL=	rip

DOCFILES=	BUGS CHANGELOG COPYING FAQ INSTALLING README
DOCDIR=		${PREFIX}/share/doc/rip

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rip ${DESTDIR}${PREFIX}/bin/rip
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for i in ${DOCFILES}; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
