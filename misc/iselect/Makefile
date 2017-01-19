# $NetBSD: Makefile,v 1.28 2017/01/19 18:52:18 agc Exp $
#

DISTNAME=		iselect-1.4.0
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.ossp.org/pkg/tool/iselect/
MASTER_SITES+=		ftp://ftp.ntua.gr/pub/utils/ossp/tool/iselect/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ossp.org/pkg/tool/iselect/
COMMENT=		Curses based Interactive Selection Tool

GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

post-configure:
	${TOUCH} ${WRKSRC}/config_ac.h.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iselect ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iselect.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
