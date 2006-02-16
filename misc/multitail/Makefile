# $NetBSD: Makefile,v 1.14 2006/02/16 06:05:31 rillig Exp $
#

DISTNAME=	multitail-3.8.5
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files

USE_NCURSES=		yes	# Needs the <panel> library.
INSTALLATION_DIRS=	bin man/man1 share/doc/multitail share/examples/multitail

CONF_FILES=	${PREFIX:Q}/share/examples/multitail/multitail.conf	\
		${PKG_SYSCONFDIR:Q}/multitail.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC:Q}/multitail.conf ${PREFIX:Q}/share/examples/multitail/
	cd ${WRKSRC} && ${INSTALL_DATA} *.txt manual*.html ${PREFIX}/share/doc/multitail/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
