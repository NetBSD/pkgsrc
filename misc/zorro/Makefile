# $NetBSD: Makefile,v 1.17 2005/01/12 21:14:20 minskim Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/22 19:55:25 jseger Exp
#

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1.8
CATEGORIES=	misc tk
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/apps/zorro-1.1p8/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Simple to-do list manager

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes
USE_X11=	yes

post-patch:
	( cd ${WRKSRC} ; ${SED} 's|@PREFIX@|'${PREFIX}'|g' \
		<zorro >zorro.BAK ; ${MV} zorro.BAK zorro )

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${PREFIX}/bin/zorro
	${INSTALL_DATA_DIR} ${PREFIX}/share/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${PREFIX}/share/zorro
	@${ECHO} ""
	@${ECHO} "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
