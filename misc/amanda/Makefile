# $NetBSD: Makefile,v 1.10 1998/06/05 14:07:22 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.0
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org

DEPENDS+=		readline-2.2:../../devel/readline
DEPENDS+=		addnerd-1.4:../../sysutils/addnerd
RUN_DEPENDS+=		gnuplot:../../graphics/gnuplot
RUN_DEPENDS+=		gtar:../../archivers/gtar

AMANDA_USER?=		backup

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} --with-group=${AMANDA_USER}
CONFIGURE_ARGS+=	--with-mmap
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

MAN8=			amadmin.8 amcheck.8 amdump.8 amflush.8 amlabel.8 \
			amrestore.8 amtape.8 amanda.8 amcleanup.8 amtoc.8 \
			amcheckdb.8 amoverview.8 amplot.8 amrecover.8 \
			amrmtape.8 amverify.8

pre-install:
	@${SETENV} ${MAKE_ENV} addnerd ${AMANDA_USER}

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
