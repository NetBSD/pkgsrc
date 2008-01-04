# $NetBSD: Makefile,v 1.25 2008/01/04 05:11:32 obache Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin share/zorro

post-patch:
	( cd ${WRKSRC} ; ${SED} 's|@PREFIX@|'${PREFIX}'|g' \
		<zorro >zorro.BAK ; ${MV} zorro.BAK zorro )

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${DESTDIR}${PREFIX}/bin/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${DESTDIR}${PREFIX}/share/zorro
	@${ECHO} ""
	@${ECHO} "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
