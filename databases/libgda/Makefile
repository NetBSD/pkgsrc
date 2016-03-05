# $NetBSD: Makefile,v 1.37 2016/03/05 11:28:11 jperkin Exp $
#

.include "Makefile.common"
.include "options.mk"

PKGREVISION=		3

PKGCONFIG_OVERRIDE=	libgda-5.0.pc.in libgda-report-5.0.pc.in \
			libgda-sqlcipher-5.0.pc.in libgda-sqlite-5.0.pc.in

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no --with-oracle=no

TEST_TARGET=		check

CHECK_INTERPRETER_SKIP=	share/libgda-5.0/gda_trml2html/trml2html.py \
			share/libgda-5.0/gda_trml2pdf/trml2pdf.py

PKG_SYSCONFSUBDIR=	libgda-5.0
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

.include "../../mk/bsd.pkg.mk"
