# $NetBSD: Makefile,v 1.9 2004/12/28 01:39:32 reed Exp $
#

PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
COMMENT=        Secure Shell client and server for V.2 SSH protocol
PKGREVISION=	2

CONFLICTS=	ssh2-nox11-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x	# be explicit

.include "../../security/ssh2/Makefile.common"
.include "../../mk/bsd.pkg.mk"
