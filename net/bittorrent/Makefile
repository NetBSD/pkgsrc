# $NetBSD: Makefile,v 1.22 2004/04/27 03:43:54 snj Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}

PYDISTUTILSPKG=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bittorrent
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/bittorrent

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
