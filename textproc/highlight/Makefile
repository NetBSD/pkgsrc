# $NetBSD: Makefile,v 1.41 2023/04/19 08:11:37 adam Exp $

PKGREVISION= 2
.include "../../textproc/libhighlight/Makefile.common"

MANCOMPRESSED=		yes

BUILD_TARGET=		cli
INSTALL_TARGET=		install-cli

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../textproc/libhighlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
