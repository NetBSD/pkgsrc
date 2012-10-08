# $NetBSD: Makefile,v 1.28 2012/10/08 09:57:42 asau Exp $

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1.8
PKGREVISION=	1
CATEGORIES=	misc tk
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/	\
		http://atreides.freenix.no/~anders/	\
		ftp://totem.fix.no/pub/mirrors/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple to-do list manager

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

USE_TOOLS+=	wish:run

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	[^[:space:]]*wish
REPLACE.wish.new=	${WISH}
REPLACE_FILES.wish=	zorro

INSTALLATION_DIRS=	bin share/zorro

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${DESTDIR}${PREFIX}/bin/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${DESTDIR}${PREFIX}/share/zorro
	@${ECHO} ""
	@${ECHO} "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
