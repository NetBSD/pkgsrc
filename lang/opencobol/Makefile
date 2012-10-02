# $NetBSD: Makefile,v 1.25 2012/10/02 20:11:47 asau Exp $
#

DISTNAME=	open-cobol-1.1
PKGNAME=	opencobol-1.1
CATEGORIES=	lang
MASTER_SITES=	http://www.sim-basis.de/

MAINTAINER=	rodo@bloerp.de
HOMEPAGE=	http://www.sim-basis.de/
COMMENT=	Open-source COBOL compiler

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db
CONFIGURE_ARGS+=	--with-lfs
CONFIGURE_ARGS+=	--without-readline
INFO_FILES=		yes

TEST_TARGET=		check

SUBST_CLASSES+=		bdb
SUBST_MESSAGE.bdb=	Fixing bdb library names.
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	configure
SUBST_SED.bdb=		-e 's,db-4.5,db5,g'
SUBST_SED.bdb+=		-e 's,db-4.4,db4,g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
