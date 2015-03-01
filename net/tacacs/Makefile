# $NetBSD: Makefile,v 1.15 2015/03/01 20:04:27 joerg Exp $

VERSION=	4.0.4.28
DISTNAME=	tacacs-F${VERSION}
PKGNAME=	tacacs-${VERSION}
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES+=	ftp://ftp.shrubbery.net/pub/tac_plus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.shrubbery.net/tac_plus/
COMMENT=	Cisco authentication, authorization, and accounting protocol daemon
LICENSE=	cisco-license

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run bison

CONFIGURE_ARGS+=	ac_cv_path_PERLV_PATH=${TOOLS_PATH.perl}
#CONFIGURE_ARGS+=--enable-debug

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=	OS=-DSOLARIS OSLIBS="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.pkg.mk"
