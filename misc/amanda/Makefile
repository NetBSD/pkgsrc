# $NetBSD: Makefile,v 1.15 1998/07/18 14:39:40 tv Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.0p1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS=		${PREFIX}/bin/libtool:../../devel/libtool
DEPENDS+=		readline-2.2:../../devel/readline
DEPENDS+=		addnerd-1.5:../../sysutils/addnerd
DEPENDS+=		gnuplot-3.5:../../graphics/gnuplot
DEPENDS+=		gtar-1.12:../../archivers/gtar

AMANDA_USER?=		backup
AMANDA_GROUP=		operator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} --with-group=${AMANDA_GROUP} \
			--with-mmap
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			LIBTOOL=${PREFIX}/bin/libtool

pre-install:
	@${SETENV} ${MAKE_ENV} addnerd -g ${AMANDA_GROUP} ${AMANDA_USER}

.include "../../mk/bsd.pkg.mk"
