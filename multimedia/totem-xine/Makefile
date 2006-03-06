# $NetBSD: Makefile,v 1.8 2006/03/06 00:18:21 wiz Exp $
#

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}
PKGREVISION=	3

COMMENT+=	(using Xine)

CONFLICTS+=	totem-[0-9]*

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
