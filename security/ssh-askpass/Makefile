# $NetBSD: Makefile,v 1.12 2010/01/27 18:23:10 joerg Exp $

DISTNAME=	x11-ssh-askpass-1.0
PKGNAME=	${DISTNAME:S/^x11-//}
PKGREVISION=	1
CATEGORIES=	security x11
MASTER_SITES=	http://www.jmknoble.net/software/x11-ssh-askpass/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jmknoble.net/software/x11-ssh-askpass/
COMMENT=	X11-based passphrase dialog for OpenSSH

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
INSTALL_TARGET=	install

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ssh-askpass
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ssh-askpass

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
