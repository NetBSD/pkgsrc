# $NetBSD: Makefile,v 1.1.1.1 2000/08/11 05:22:57 jlam Exp $

DISTNAME=	x11-ssh-askpass-1.0
PKGNAME=	${DISTNAME:S/^x11-//}
CATEGORIES=	security x11
MASTER_SITES=	http://www.ntrnet.net/~jmknoble/software/x11-ssh-askpass/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ntrnet.net/~jmknoble/software/x11-ssh-askpass/

USE_X11BASE=	# defined
USE_IMAKE=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ssh-askpass
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ssh-askpass

.include "../../mk/bsd.pkg.mk"
