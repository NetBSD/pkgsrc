# $NetBSD: Makefile,v 1.17 2009/02/21 19:39:43 tnn Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ENV+=		ac_cv_prog_TCLSH_CMD=""
CONFIGURE_ARGS+=	--enable-load-extension
CONFIGURE_ARGS+=	--with-readline-inc=

# Uses dlopen and friends but doesn't use -ldl on Linux.
# See http://www.sqlite.org/cvstrac/tktview?tn=3555
LIBS+=			${BUILDLINK_LDADD.dl}

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
