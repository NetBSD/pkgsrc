# $NetBSD: Makefile,v 1.15 2012/10/08 09:57:37 asau Exp $
#

DISTNAME=	sci-0.5.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://linuxparts.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxparts.com/software.html
COMMENT=	Curses based data entry via templates

GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	share/doc/sci share/examples/sci

post-install:
	for i in COPYING README INSTALL NEWS ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/doc/sci ; \
	   done
	for i in samples/* ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/examples/sci ; \
	   done

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
