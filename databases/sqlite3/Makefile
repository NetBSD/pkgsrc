# $NetBSD: Makefile,v 1.5 2005/04/14 05:45:51 xtraeme Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
