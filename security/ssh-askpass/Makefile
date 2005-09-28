# $NetBSD: Makefile,v 1.7 2005/09/28 20:52:26 rillig Exp $

DISTNAME=	x11-ssh-askpass-1.0
PKGNAME=	${DISTNAME:S/^x11-//}
CATEGORIES=	security x11
MASTER_SITES=	http://www.jmknoble.net/software/x11-ssh-askpass/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.jmknoble.net/software/x11-ssh-askpass/
COMMENT=	X11-based passphrase dialog for OpenSSH

USE_IMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ssh-askpass
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ssh-askpass

.include "../../mk/bsd.pkg.mk"
