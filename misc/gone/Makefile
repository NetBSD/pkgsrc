# $NetBSD: Makefile,v 1.10 2010/02/26 10:28:33 wiz Exp $
#

DISTNAME=	gone-1.3.5
CATEGORIES=	misc
MASTER_SITES=	http://jaguar.ir.miami.edu/~marcus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jaguar.ir.miami.edu/~marcus/
COMMENT=	Terminal locking utility with many improvements over lock(1)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	with_setuid=no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
