# $NetBSD: Makefile,v 1.51 2024/05/29 16:34:35 adam Exp $

PKGREVISION= 1
.include "../../textproc/libhighlight/Makefile.common"

MANCOMPRESSED=		yes

BUILD_TARGET=		cli
INSTALL_TARGET=		install-cli

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../textproc/libhighlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
