# $NetBSD: Makefile,v 1.7 2004/07/25 12:35:06 grant Exp $
#

PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
COMMENT=        Secure Shell client and server for V.2 SSH protocol

CONFLICTS=	ssh2-nox11-[0-9]*
CONFLICTS+=	openssh-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x	# be explicit

.include "../../security/ssh2/Makefile.common"
.include "../../mk/bsd.pkg.mk"
