# $NetBSD: Makefile,v 1.3 2006/10/04 21:59:35 wiz Exp $
#

DISTNAME=	pdumpfs-${VER}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://0xcc.net/pdumpfs/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://0xcc.net/pdumpfs/
COMMENT=	Simple daily backup system similar to Plan9's dumpfs

VER=		1.3
BUILD_TARGET=	pdumpfs

REPLACE_RUBY=	pdumpfs.in

INSTALLATION_DIRS=	share/doc/pdumpfs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdumpfs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man8/pdumpfs.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/ja/man8/pdumpfs.8 ${PREFIX}/man/ja_JP.EUC/man8
	cd ${WRKSRC}/doc && \
		${PAX} -rw -pp -pm . ${PREFIX}/share/doc/pdumpfs

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
