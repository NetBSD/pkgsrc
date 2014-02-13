# $NetBSD: Makefile,v 1.73 2014/02/13 07:30:31 adam Exp $

DISTNAME=	sqlite-autoconf-3080301
PKGNAME=	sqlite3-3.8.3.1
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/2014/ \
		http://www.sqlite.org/2014/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqlite.org/
COMMENT=	SQL Database Engine in a C Library
LICENSE=	public-domain

.include "options.mk"

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	sqlite3.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# In the past, Linux had database corruption issues with pread, so
# only enable it on safe platforms.
CFLAGS.NetBSD+=		-DUSE_PREAD

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=		-DSQLITE_ENABLE_LOCKING_STYLE=0
.endif

# This define includes the sqlite3_unlock_notify() API in the build.
# It is required by Firefox 4.x.
CFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
# The following are defined in the NetBSD builtin version.
CFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA
CFLAGS+=		-DSQLITE_ENABLE_LOAD_EXTENSION

# Uses dlopen and friends but doesn't use -ldl on Linux.
# See http://www.sqlite.org/cvstrac/tktview?tn=3555
LIBS+=			${BUILDLINK_LDADD.dl}

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
