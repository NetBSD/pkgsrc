# $NetBSD: Makefile,v 1.3 2005/03/07 14:59:06 adam Exp $

DISTNAME=	sqlite-3.1.3
PKGNAME=	${DISTNAME:S/-/3-/}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/ \
		http://www.sqlite.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.hwaci.com/sw/sqlite/
COMMENT=	SQL Database Engine in a C Library

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	${WRKDIR}/sqlite/sqlite3.pc.in

.include "options.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
