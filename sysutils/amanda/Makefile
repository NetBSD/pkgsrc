# $NetBSD: Makefile,v 1.19 1999/01/03 13:13:13 frueauf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.0p1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		readline-2.2:../../devel/readline
DEPENDS+=		addnerd-1.6:../../sysutils/addnerd
DEPENDS+=		gnuplot-3.5:../../graphics/gnuplot
DEPENDS+=		gtar-1.12:../../archivers/gtar

AMANDA_USER?=		backup
AMANDA_GROUP=		operator

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} --with-group=${AMANDA_GROUP} \
			--with-mmap --with-amandahosts
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

pre-install:
	@${SETENV} ${MAKE_ENV} addnerd -g ${AMANDA_GROUP} ${AMANDA_USER}

.include "../../mk/bsd.pkg.mk"
