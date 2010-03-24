# $NetBSD: Makefile,v 1.19 2010/03/24 19:43:25 asau Exp $
#

DISTNAME=		open-cobol-0.32
PKGNAME=		opencobol-0.32
PKGREVISION=		3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opencobol.org/
COMMENT=		Open-source COBOL compiler

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

TEST_TARGET=		check

CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--with-lfs

# XXX: followings can be removed when update to 0.33.
SUBST_CLASSES+=		fixchkgmp
SUBST_STAGE.fixchkgmp=	pre-configure
SUBST_FILES.fixchkgmp=	configure
SUBST_SED.fixchkgmp=	-e 's|__gmp_rand|__gmp_randinit|g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.if ${BDB_TYPE} != "db1"
CONFIGURE_ARGS+=	--with-db
.endif
.include "../../mk/bsd.pkg.mk"
