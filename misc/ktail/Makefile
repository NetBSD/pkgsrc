# $NetBSD: Makefile,v 1.1.1.1 2001/04/16 23:19:11 zuntum Exp $
#

DISTNAME=	ktail-0.5.1
CATEGORIES=	misc
MASTER_SITES=	http://www.franken.de/users/duffy1/rjakob/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.franken.de/users/duffy1/rjakob/
COMMENT=	ktail monitors multiple files and/or command output in one window

DEPENDS+=       kdebase>=2.1:../../x11/kdebase2
BUILD_USES_MSGFMT=      yes

GNU_CONFIGURE=	YES

.include "../../x11/kde2/Makefile.part2"

.include "../../mk/bsd.pkg.mk"
