# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:56 joerg Exp $
#

DISTNAME=	screentest-1.0
PKGREVISION=	4
CATEGORIES=	sysutils x11
MASTER_SITES=	ftp://ftp.linux.cz/pub/linux/people/jan_kasprzak/screentest/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fi.muni.cz/~kas/screentest/
COMMENT=	CRT screen testing utility using GTK+

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/screentest
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/screentest
.endfor

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
