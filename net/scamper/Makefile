# $NetBSD: Makefile,v 1.28 2026/04/05 20:55:32 maya Exp $
#

DISTNAME=	scamper-cvs-20260331
PKGNAME=	${DISTNAME:S/-cvs//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.caida.org/catalog/software/scamper/code/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	https://www.caida.org/catalog/software/scamper/
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement
LICENSE=	gnu-gpl-v2

USE_FEATURES+=	inet6

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-privsep-dir=${VARBASE}/chroot/scamper
CONFIGURE_ARGS+=	--with-privsep-user=_scamper
CONFIGURE_ARGS+=	--with-bz2
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-lzma
CONFIGURE_ARGS+=	--with-pcre2
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-sc_hoiho
CONFIGURE_ARGS+=	--enable-sc_minrtt
CONFIGURE_ARGS+=	--enable-sc_uptime
USE_LIBTOOL=		yes

PKG_GROUPS=		_scamper
PKG_USERS=		_scamper:_scamper
PKG_HOME._scamper=	${VARBASE}/chroot/scamper

OWN_DIRS=		${VARBASE}/chroot/scamper
AUTO_MKDIRS=		yes

SPECIAL_PERMS=		bin/scamper ${SETUID_ROOT_PERMS}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
