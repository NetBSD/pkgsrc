# $NetBSD: Makefile,v 1.4 2003/07/17 22:53:17 grant Exp $

DISTNAME=	x11-ssh-askpass-1.0
PKGNAME=	${DISTNAME:S/^x11-//}
CATEGORIES=	security x11
MASTER_SITES=	http://www.ntrnet.net/~jmknoble/software/x11-ssh-askpass/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ntrnet.net/~jmknoble/software/x11-ssh-askpass/
COMMENT=	X11-based passphrase dialog for OpenSSH

USE_X11BASE=	# defined
USE_IMAKE=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ssh-askpass
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ssh-askpass

.include "../../mk/bsd.pkg.mk"
