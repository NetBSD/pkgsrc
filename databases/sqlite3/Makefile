# $NetBSD: Makefile,v 1.12 2008/10/02 11:15:17 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		1

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--enable-load-extension
CONFIGURE_ARGS+=	--with-readline-inc=

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
