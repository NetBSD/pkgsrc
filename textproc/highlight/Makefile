# $NetBSD: Makefile,v 1.10 2018/04/08 19:40:29 schmonz Exp $

PKGREVISION=		1
.include "../../textproc/highlight/Makefile.common"

MANCOMPRESSED=		yes

BUILD_TARGET=		cli
INSTALL_TARGET=		install-cli

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../textproc/libhighlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
