# $NetBSD: Makefile,v 1.2 2004/07/25 12:35:06 grant Exp $
#

PKGNAME=	${DISTNAME:C/ssh-/ssh2-nox11-/}
COMMENT=        Secure Shell client and server for V.2 SSH protocol without X11 support
CONFLICTS=		ssh2-[0-9]*
CONFLICTS+=		openssh-[0-9]*
CONFIGURE_ARGS+=	--without-x	# be explicit

.include "../../security/ssh2/Makefile.common"
.include "../../mk/bsd.pkg.mk"
