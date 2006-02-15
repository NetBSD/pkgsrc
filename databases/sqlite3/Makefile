# $NetBSD: Makefile,v 1.7 2006/02/15 19:50:52 drochner Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
