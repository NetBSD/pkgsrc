# $NetBSD: Makefile,v 1.9 2021/04/25 06:35:22 wiz Exp $

DISTNAME=	tcx-linux
PKGNAME=	tcx-19940124
CATEGORIES=	sysutils
#MASTER_SITES=	ftp://ibiblio.unc.edu/pub/Linux/utils/compress/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Transparently compress executables

SPECIAL_PERMS+=	bin/untcx ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS+=	bin

WRKSRC=		${WRKDIR}/tcx

post-patch:
	cd ${WRKSRC}; ${MV} config.h config.h-pre; ${SED} -e 's|@PREFIX@|"${PREFIX}"|g' < config.h-pre > config.h

.include "../../mk/bsd.pkg.mk"
