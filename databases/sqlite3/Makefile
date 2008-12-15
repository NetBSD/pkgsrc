# $NetBSD: Makefile,v 1.14 2008/12/15 09:03:26 martin Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--enable-load-extension
CONFIGURE_ARGS+=	--with-readline-inc=

TEST_TARGET=	fulltest

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
