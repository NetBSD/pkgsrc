# $NetBSD: Makefile,v 1.1.1.1 1999/09/06 18:11:22 bad Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-plot-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-2.4.1p1:../../sysutils/amanda-server

USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
AMANDA_GROUP=		operator
.elif ${OPSYS} == "SunOS"
AMANDA_GROUP=		sysadmin
.endif

AMANDA_USER?=		backup
AMANDA_VAR?=		/var/amanda

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/gnuplot"
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} \
			--with-group=${AMANDA_GROUP} \
			--with-owner=root \
			--with-mmap --with-amandahosts \
			--with-includes=${PREFIX}/include \
			--with-libraries=${PREFIX}/lib \
			--localstatedir=${AMANDA_VAR} \
			--with-gnutar-listdir=${AMANDA_VAR}/gnutar-lists \
			--with-dump-honor-nodump \
			--without-client

.include "../../mk/bsd.pkg.mk"
