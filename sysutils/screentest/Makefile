# $NetBSD: Makefile,v 1.1.1.1 2003/01/08 23:15:12 jmmv Exp $
#

DISTNAME=	screentest-1.0
CATEGORIES=	sysutils x11
MASTER_SITES=	ftp://ftp.linux.cz/pub/linux/people/jan_kasprzak/screentest/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fi.muni.cz/~kas/screentest/
COMMENT=	CRT screen testing utility using GTK+

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/screentest
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/screentest
.endfor
.undef f

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
