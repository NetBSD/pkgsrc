# $NetBSD: Makefile,v 1.6 2003/05/10 10:02:34 seb Exp $
#

PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
COMMENT=        Secure Shell client and server for V.2 SSH protocol

CONFLICTS=	ssh2-nox11-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x	# be explicit

.include "../../security/ssh2/Makefile.common"
.include "../../mk/bsd.pkg.mk"
