# $NetBSD: Makefile,v 1.18 2006/06/25 00:01:44 hubertf Exp $
#

DISTNAME=	multitail-4.0.6
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files

USE_NCURSES=		yes	# Needs the <panel> library.
INSTALLATION_DIRS=	bin man/man1 share/doc/multitail share/examples/multitail

CONF_FILES=	${PREFIX:Q}/share/examples/multitail/multitail.conf	\
		${PKG_SYSCONFDIR:Q}/multitail.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/multitail ${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/multitail.1 ${PREFIX:Q}/man/man1/
	${INSTALL_DATA} ${WRKSRC:Q}/multitail.conf ${PREFIX:Q}/share/examples/multitail/
	cd ${WRKSRC:Q} && ${INSTALL_DATA} *.txt manual*.html ${PREFIX:Q}/share/doc/multitail/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
