# $NetBSD: Makefile,v 1.9 2014/08/18 01:21:49 schmonz Exp $

.include "../../textproc/highlight/Makefile.common"

MANCOMPRESSED=		yes

BUILD_TARGET=		cli

EGDIR=			${PREFIX}/share/examples/highlight
CONF_FILES=		${EGDIR}/filetypes.conf			\
			${PKG_SYSCONFDIR}/filetypes.conf

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
