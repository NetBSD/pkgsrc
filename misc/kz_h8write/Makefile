# $NetBSD: Makefile,v 1.1 2013/04/30 13:29:48 ryoon Exp $
#

DISTNAME=	kz_h8write-v0.2.1
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=kz-h8write/57645/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/kz-h8write/
COMMENT=	Flash writer for H8/3069F, mainly for KOZOS
LICENSE=	mit

WRKSRC=	${WRKDIR}/PackageFiles/src

INSTALLATION_DIRS+=	bin share/kz_h8write

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kz_h8write ${DESTDIR}/${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../doc/README.txt \
		${DESTDIR}/${PREFIX}/share/kz_h8write

.include "../../mk/bsd.pkg.mk"
