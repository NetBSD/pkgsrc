# $NetBSD: Makefile,v 1.14 2006/09/16 15:36:12 jmmv Exp $
#

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}
PKGREVISION=	1

COMMENT+=	(using Xine)

CONFLICTS+=	totem-[0-9]*

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
