# $NetBSD: Makefile,v 1.2 2005/11/25 21:23:16 wiz Exp $
#

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}
PKGREVISION=	1

COMMENT+=	(using Xine)

CONFLICTS+=	totem-[0-9]*

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
