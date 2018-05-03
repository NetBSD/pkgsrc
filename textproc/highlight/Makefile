# $NetBSD: Makefile,v 1.12 2018/05/03 13:13:50 schmonz Exp $

.include "../../textproc/libhighlight/Makefile.common"

MANCOMPRESSED=		yes

BUILD_TARGET=		cli
INSTALL_TARGET=		install-cli

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../textproc/libhighlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
