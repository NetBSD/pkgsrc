# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:16 tv Exp $
#

DISTNAME=	screentest-1.0
PKGREVISION=	3
CATEGORIES=	sysutils x11
MASTER_SITES=	ftp://ftp.linux.cz/pub/linux/people/jan_kasprzak/screentest/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fi.muni.cz/~kas/screentest/
COMMENT=	CRT screen testing utility using GTK+

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/screentest
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/screentest
.endfor
.undef f

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
