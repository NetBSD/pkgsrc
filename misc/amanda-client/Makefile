# $NetBSD: Makefile,v 1.1.1.1 1999/02/23 17:03:42 bouyer Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-client-2.4.1p1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		readline-2.2:../../devel/readline
DEPENDS+=		gtar-1.12:../../archivers/gtar
DEPENDS+=		amanda-common-2.4.1p1:../amanda-common

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
AMANDA_USER?=		backup
AMANDA_GROUP=		operator

CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} \
			--with-group=${AMANDA_GROUP} \
			--with-mmap --with-amandahosts \
			--with-includes=${PREFIX}/include \
			--with-libraries=${PREFIX}/lib \
			--with-dump-honor-nodump \
			--without-server --without-restore

.if defined(AMANDA_SMB)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		samba-2.0.2:../../net/samba
.endif

CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"


.include "../../mk/bsd.pkg.mk"
