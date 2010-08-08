# $NetBSD: Makefile,v 1.31 2010/08/08 12:04:37 adam Exp $

DISTNAME=	sqlite-amalgamation-3.7.0.1
PKGNAME=	${DISTNAME:S/sqlite-amalgamation/sqlite3/}
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/ \
		http://www.sqlite.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqlite.org/
COMMENT=	SQL Database Engine in a C Library
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/sqlite-${PKGVERSION_NOREV}

PKGCONFIG_OVERRIDE+=	sqlite3.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--with-readline-inc= --enable-threadsafe

.include "../../mk/bsd.prefs.mk"

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=		-DSQLITE_ENABLE_LOCKING_STYLE=0
.endif

# This define includes the sqlite3_unlock_notify() API in the build.
# It is required by Firefox 4.x.
CFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1

# Uses dlopen and friends but doesn't use -ldl on Linux.
# See http://www.sqlite.org/cvstrac/tktview?tn=3555
LIBS+=			${BUILDLINK_LDADD.dl}

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
