# $NetBSD: Makefile,v 1.2 1999/03/04 09:30:45 tron Exp $
#

DISTNAME=	gtksamba-0.3.2pl1
PKGNAME=	gtksamba-0.3.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.open-systems.com/gtksamba/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.open-systems.com/gtksamba.html

DEPENDS+=	gtk+-1.2.0:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="-DPREFIX='\"${PREFIX}\"' ${CFLAGS}"

post-install:
	@ ${MKDIR} ${PREFIX}/share/doc/gtksamba
.for file in COPYING README TODO ChangeLog
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtksamba
.endfor

.include "../../mk/bsd.pkg.mk"
