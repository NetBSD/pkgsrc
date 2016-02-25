# $NetBSD: Makefile,v 1.18 2016/02/25 16:20:53 jperkin Exp $

VERSION=	4.0.4.28
DISTNAME=	tacacs-F${VERSION}
PKGNAME=	tacacs-${VERSION}
PKGREVISION=	3
CATEGORIES=	net security
MASTER_SITES+=	ftp://ftp.shrubbery.net/pub/tac_plus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.shrubbery.net/tac_plus/
COMMENT=	Cisco authentication, authorization, and accounting protocol daemon
LICENSE=	cisco-license

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run flex bison

CONFIGURE_ARGS+=	ac_cv_path_PERLV_PATH=${TOOLS_PATH.perl}

OPSYSVARS+=		MAKE_FLAGS
MAKE_FLAGS.SunOS+=	OS=-DSOLARIS OSLIBS="-lsocket -lnsl"

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.pkg.mk"
