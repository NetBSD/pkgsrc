# $NetBSD: Makefile,v 1.5 1999/04/21 15:31:05 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-client-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		readline-2.2:../../devel/readline
DEPENDS+=		gtar-1.12:../../archivers/gtar
DEPENDS+=		amanda-common-2.4.1p1:../amanda-common

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

.if defined(AMANDA_SMB)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		samba-2.0.3:../../net/samba
.endif

CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"


.include "../../mk/bsd.pkg.mk"
