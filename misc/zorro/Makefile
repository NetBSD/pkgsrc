# $NetBSD: Makefile,v 1.8 1999/04/26 18:56:15 garbled Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/22 19:55:25 jseger Exp
#

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1.8
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/apps/zorro-1.1p8/

MAINTAINER=	shanee@augusta.de

DEPENDS+=	tk-8.0.5:../../x11/tk80

NO_BUILD=	yes
USE_X11=	yes

post-patch:
	( cd ${WRKSRC} ; ${SED} 's|/usr/local|'${PREFIX}'|g' \
		<zorro >zorro.BAK ; ${MV} zorro.BAK zorro )

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${PREFIX}/bin/zorro
	${MKDIR} ${PREFIX}/share/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${PREFIX}/share/zorro
	@echo ""
	@echo "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@echo ""

.include "../../mk/bsd.pkg.mk"
