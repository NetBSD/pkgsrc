# $NetBSD: Makefile,v 1.10 2006/03/30 21:36:13 jmmv Exp $
#

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}

COMMENT+=	(using Xine)

CONFLICTS+=	totem-[0-9]*

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
