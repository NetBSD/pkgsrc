# $NetBSD: Makefile,v 1.34 2010/02/11 23:14:14 joerg Exp $

DISTNAME=	wu-ftpd-2.6.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://mirror.aarnet.edu.au/pub/wu-ftpd/wu-ftpd/ \
		http://mirror.aarnet.edu.au/pub/wu-ftpd/wu-ftpd/ \
		ftp://ftp.tuwien.ac.at/infosys/servers/ftp/wu-ftpd/wu-ftpd/ \
		http://gd.tuwien.ac.at/infosys/servers/ftp/wu-ftpd/wu-ftpd/ \
		ftp://ftp.freenet.de/pub/ftp.wu-ftpd.org/pub/wu-ftpd/ \
		ftp://ftp.nl.uu.net/pub/unix/ftp/wu-ftpd/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/ftpd/wu-ftpd/wu-ftpd.org/wu-ftpd/ \
		ftp://ftp.sunet.se/pub/nir/ftp/servers/wuarchive-ftpd/wu-ftpd/

PATCHFILES=	realpath.patch connect-dos.patch
PATCH_SITES=	ftp://ftp.sunet.se/pub/nir/ftp/servers/wuarchive-ftpd/wu-ftpd/patches/apply_to_2.6.2/	
MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.wu-ftpd.org/
COMMENT=	Replacement ftp server for Un*x systems

PKG_DESTDIR_SUPPORT=	user-destdir

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
