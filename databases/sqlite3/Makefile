# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:37 joerg Exp $

.include "Makefile.common"

PKGREVISION=		1

CONFIGURE_ARGS+=	--disable-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
