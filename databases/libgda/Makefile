# $NetBSD: Makefile,v 1.51 2023/11/08 13:18:24 wiz Exp $

PKGREVISION= 11
.include "Makefile.common"
.include "options.mk"

PKGCONFIG_OVERRIDE+=	libgda-5.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-report-5.0.pc.in

CONFIGURE_ARGS+=	--with-bdb=no
CONFIGURE_ARGS+=	--with-oracle=no

TEST_TARGET=		check

CHECK_INTERPRETER_SKIP=		share/libgda-5.0/gda_trml2html/trml2html.py
CHECK_INTERPRETER_SKIP+=	share/libgda-5.0/gda_trml2pdf/trml2pdf.py

PKG_SYSCONFSUBDIR=	libgda-5.0
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

.include "../../mk/bsd.pkg.mk"
