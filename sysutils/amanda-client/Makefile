# $NetBSD: Makefile,v 1.10 1999/09/04 01:08:53 bad Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-client-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		readline-4.0:../../devel/readline
DEPENDS+=		gtar-1.12:../../archivers/gtar
DEPENDS+=		amanda-common-2.4.1p1:../../sysutils/amanda-common

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
AMANDA_GROUP=		operator
.elif ${OPSYS} == "SunOS"
AMANDA_GROUP=		sysadmin
.endif

AMANDA_USER?=		backup
AMANDA_VAR?=		/var/amanda

CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} \
			--with-group=${AMANDA_GROUP} \
			--with-owner=root \
			--with-mmap --with-amandahosts \
			--with-includes=${PREFIX}/include \
			--with-libraries=${PREFIX}/lib \
			--localstatedir=${AMANDA_VAR} \
			--with-gnutar-listdir=${AMANDA_VAR}/gnutar-lists \
			--with-dump-honor-nodump \
			--without-server --without-restore

BUILD_DEFS+=		AMANDA_USER AMANDA_SMB AMANDA_VAR

.if defined(AMANDA_SMB)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		samba-2.0.5a:../../net/samba
.endif

.include "../../mk/bsd.pkg.mk"
