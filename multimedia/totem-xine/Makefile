# $NetBSD: Makefile,v 1.5 2006/01/12 16:57:50 jmmv Exp $
#

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}

COMMENT+=	(using Xine)

CONFLICTS+=	totem-[0-9]*

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
