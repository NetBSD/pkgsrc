# $NetBSD: Makefile,v 1.1.1.1 2005/01/16 02:00:33 tv Exp $

DISTNAME=		sqlite-3.0.8
PKGNAME=		${DISTNAME:S/-/3-/}
CATEGORIES=		databases
MASTER_SITES=		http://www.hwaci.com/sw/sqlite/ \
			http://www.sqlite.org/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine in a C Library

WRKSRC=			${WRKDIR}/sqlite
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-tcl

PKGCONFIG_OVERRIDE=	${WRKDIR}/sqlite/sqlite3.pc.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
