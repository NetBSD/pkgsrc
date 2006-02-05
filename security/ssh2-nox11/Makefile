# $NetBSD: Makefile,v 1.4.8.1 2006/02/05 22:22:37 salo Exp $
#

PKGNAME=	${DISTNAME:C/ssh-/ssh2-nox11-/}
COMMENT=        Secure Shell client and server for V.2 SSH protocol without X11 support
PKGREVISION=	3
CONFLICTS=		ssh2-[0-9]*
CONFIGURE_ARGS+=	--without-x	# be explicit

.include "../../security/ssh2/Makefile.common"
.include "../../mk/bsd.pkg.mk"
