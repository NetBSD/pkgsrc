# $NetBSD: Makefile,v 1.9 2007/05/20 00:17:01 heinz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--disable-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 \
		${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
