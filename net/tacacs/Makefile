# $NetBSD: Makefile,v 1.27 2022/06/28 11:35:20 wiz Exp $

VERSION=	4.0.4.28
DISTNAME=	tacacs-F${VERSION}
PKGNAME=	tacacs-${VERSION}
PKGREVISION=	9
CATEGORIES=	net security
MASTER_SITES+=	ftp://ftp.shrubbery.net/pub/tac_plus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.shrubbery.net/tac_plus/
COMMENT=	Cisco authentication, authorization, and accounting protocol daemon
LICENSE=	cisco-license

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run flex bison

CONFIGURE_ARGS+=	ac_cv_path_PERLV_PATH=${TOOLS_PATH.perl}

MAKE_FLAGS.SunOS+=	OS=-DSOLARIS OSLIBS="-lsocket -lnsl"

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
