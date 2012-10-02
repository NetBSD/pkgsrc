# $NetBSD: Makefile,v 1.18 2012/10/02 23:48:02 asau Exp $
#

DISTNAME=	nspmod-0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/sound/players/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.jeton.or.jp/users/toru/www/orgsoft/index.html
COMMENT=	MOD/S3M/MTM tracker that does its own DSP, uses VoxWare v2.90+

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspmod ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nspmod.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
