# $NetBSD: Makefile,v 1.1 2015/03/01 21:05:54 mspo Exp $

VERSION=	0.9.14
DISTNAME=	mdb-${VERSION}
PKGNAME=	lmdb-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	http://ftp.netbsd.org/pub/pkgsrc/distfiles/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://symas.com/mdb/
COMMENT=	Symas Lightning Memory-Mapped Database
USE_TOOLS+=	gmake
INSTALLATION_DIRS+=	man/man1
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	bin
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/mdb-mdb
BUILD_DIRS=	${WRKSRC}/libraries/liblmdb

SUBST_CLASSES+=			makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing CFLAGS and PREFIX
SUBST_FILES.makefile=	libraries/liblmdb/Makefile
SUBST_SED.makefile=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,XCFLAGS),XCFLAGS) -D_SEM_SEMUN_UNDEFINED ,g'
SUBST_SED.makefile+=	-e 's,gcc,${CC},g'
SUBST_SED.makefile+=	-e 's,do cp,do install,g'

.include "../../mk/bsd.pkg.mk"
