# $NetBSD: Makefile,v 1.45 2019/02/04 09:34:49 wiz Exp $

DISTNAME=	wu-ftpd-2.6.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nl.uu.net/pub/unix/ftp/wu-ftpd/
MASTER_SITES+=	ftp://ftp.u-aizu.ac.jp/pub/net/ftpd/wu-ftpd/wu-ftpd.org/wu-ftpd/

PATCHFILES=	realpath.patch connect-dos.patch
#PATCH_SITES=	ftp://ftp.sunet.se/pub/nir/ftp/servers/wuarchive-ftpd/wu-ftpd/patches/apply_to_2.6.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.wu-ftpd.org/
COMMENT=	Replacement ftp server for Un*x systems

CONFLICTS=	wu-ftpd-vr-[0-9]*
CONFLICTS+=	beroftpd-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*
CONFLICTS+=	lukemftpd-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	yacc

CONFIGURE_ARGS+=--enable-quota --enable-noop --enable-skey

DIST_SUBDIR=		wu-ftpd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && make(do-configure)
CFLAGS+=	-DHAVE_SYS_MOUNT
.endif

MAKE_ENV+=	INSTALL=${INSTALL:Q}
MAKE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=	INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_ENV+=	INSTALL_MAN=${INSTALL_MAN:Q}

.include "../../mk/bsd.pkg.mk"
