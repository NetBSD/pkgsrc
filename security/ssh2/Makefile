# $NetBSD: Makefile,v 1.11 2005/06/01 18:03:21 jlam Exp $
#

PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
COMMENT=        Secure Shell client and server for V.2 SSH protocol
PKGREVISION=	3

CONFLICTS=	ssh2-nox11-[0-9]*

CONFIGURE_ARGS+=	--with-x	# be explicit

.include "../../mk/x11.buildlink3.mk"
.include "../../security/ssh2/Makefile.common"
.include "../../mk/bsd.pkg.mk"
