# $NetBSD: Makefile,v 1.20 2004/03/26 02:27:47 wiz Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}
PKGREVISION=	1

PYDISTUTILSPKG=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bittorrent
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/bittorrent

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
