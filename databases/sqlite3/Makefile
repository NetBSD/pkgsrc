# $NetBSD: Makefile,v 1.4 2005/03/23 22:08:06 jmmv Exp $

.include "Makefile.common"

PKGREVISION=		2

CONFIGURE_ARGS+=	--disable-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
