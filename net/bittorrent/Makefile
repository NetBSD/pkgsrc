# $NetBSD: Makefile,v 1.18 2004/03/12 23:43:05 recht Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}

PYDISTUTILSPKG=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bittorrent
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/bittorrent

.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
