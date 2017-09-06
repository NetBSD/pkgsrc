# $NetBSD: Makefile,v 1.8 2017/09/06 10:40:31 wiz Exp $
#

DISTNAME=	xtail-2.1
CATEGORIES=	misc
#MASTER_SITES=	http://www.unicom.com/sw/xtail/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.unicom.com/sw/xtail/
COMMENT=	Like "tail -f" on a bunch of files at once

GNU_CONFIGURE=	YES

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtail ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtail.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
