# $NetBSD: Makefile,v 1.1.1.1 1999/02/23 17:03:41 bouyer Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-common-2.4.1p1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		addnerd-1.6:../../sysutils/addnerd

AMANDA_USER?=		backup
AMANDA_GROUP=		operator

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} \
			--with-group=${AMANDA_GROUP} \
			--with-mmap --with-amandahosts \
			--with-includes=${PREFIX}/include \
			--with-libraries=${PREFIX}/lib \
			--with-dump-honor-nodump \
			--without-server --without-restore --without-client

CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

pre-install:
	@${SETENV} ${MAKE_ENV} addnerd -g ${AMANDA_GROUP} ${AMANDA_USER}

.include "../../mk/bsd.pkg.mk"
