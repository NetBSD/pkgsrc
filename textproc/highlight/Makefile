# $NetBSD: Makefile,v 1.49 2024/04/06 08:06:47 wiz Exp $

PKGREVISION= 1
.include "../../textproc/libhighlight/Makefile.common"

MANCOMPRESSED=		yes

BUILD_TARGET=		cli
INSTALL_TARGET=		install-cli

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../textproc/libhighlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
