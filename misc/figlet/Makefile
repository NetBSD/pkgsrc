# $NetBSD: Makefile,v 1.13 2004/03/28 19:40:23 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1997/06/29 09:56:32 obrien Exp
#

DISTNAME=	figlet221
PKGNAME=	figlet-2.2.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://www.figlet.org/
COMMENT=	Print text banners in fancy ASCII art characters

pre-install:	
		${INSTALL_MAN_DIR} ${PREFIX}/man/man6

.include "../../mk/bsd.pkg.mk"
