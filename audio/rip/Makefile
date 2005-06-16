# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:39 jlam Exp $
#

DISTNAME=	rip-1.07
CATEGORIES=	audio perl5
MASTER_SITES=	http://rip.sourceforge.net/download/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://rip.sourceforge.net/
COMMENT=	Command-line based audio CD ripper and encoder

DEPENDS+=	p5-CDDB_get>=2.23:../../audio/p5-CDDB_get
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info

USE_PERL5=	yes
NO_BUILD=	# defined
REPLACE_PERL=	rip

DOCFILES=	BUGS CHANGELOG COPYING FAQ INSTALLING README
DOCDIR=		${PREFIX}/share/doc/rip

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rip ${PREFIX}/bin/rip
	${INSTALL_DATA_DIR} ${DOCDIR}
	for i in ${DOCFILES}; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
