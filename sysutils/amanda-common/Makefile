# $NetBSD: Makefile,v 1.2 1999/02/25 15:54:00 bouyer Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-common-2.4.1p1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		addnerd-1.6:../../sysutils/addnerd

.include "../../mk/bsd.prefs.mk"
AMANDA_USER?=		backup
AMANDA_GROUP=		operator
AMANDA_VAR?=		/var/amanda

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} \
			--with-group=${AMANDA_GROUP} \
			--with-owner=root \
			--with-mmap --with-amandahosts \
			--with-includes=${PREFIX}/include \
			--with-libraries=${PREFIX}/lib \
			--localstatedir=${AMANDA_VAR} \
			--with-gnutar-listdir=${AMANDA_VAR}/gnutar-lists \
			--with-dump-honor-nodump \
			--without-server --without-restore --without-client

CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

pre-install:
	@${SETENV} ${MAKE_ENV} addnerd -g ${AMANDA_GROUP} ${AMANDA_USER}

.include "../../mk/bsd.pkg.mk"
