# $NetBSD: Makefile,v 1.13 2003/12/03 22:14:46 kristerw Exp $
#

DISTNAME=	gtksamba-0.3.2pl1
PKGNAME=	gtksamba-0.3.2.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.open-systems.com/gtksamba/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.open-systems.com/gtksamba.html
COMMENT=	Samba configuration tool for X Window System

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
CONFIGURE_ENV+=	CFLAGS="-DPREFIX='\"${PREFIX}\"' ${CFLAGS}"

post-install:
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtksamba
.for file in COPYING README TODO ChangeLog
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtksamba
.endfor

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
