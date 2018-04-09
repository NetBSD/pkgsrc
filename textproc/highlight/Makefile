# $NetBSD: Makefile,v 1.11 2018/04/09 20:17:46 schmonz Exp $

PKGREVISION=		2
.include "../../textproc/highlight/Makefile.common"

MANCOMPRESSED=		yes

BUILD_TARGET=		cli
INSTALL_TARGET=		install-cli

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../textproc/libhighlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
