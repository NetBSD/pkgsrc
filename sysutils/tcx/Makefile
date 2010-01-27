# $NetBSD: Makefile,v 1.7 2010/01/27 20:19:36 joerg Exp $

DISTNAME=	tcx-linux
PKGNAME=	tcx-19940124
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ibiblio.unc.edu/pub/Linux/utils/compress/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Transparently compress executables

PKG_DESTDIR_SUPPORT=	user-destdir
SPECIAL_PERMS+=	bin/untcx ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS+=	bin

WRKSRC=		${WRKDIR}/tcx

post-patch:
	cd ${WRKSRC}; ${MV} config.h config.h-pre; ${SED} -e 's|@PREFIX@|"${PREFIX}"|g' < config.h-pre > config.h

.include "../../mk/bsd.pkg.mk"
