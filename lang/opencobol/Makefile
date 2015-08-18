# $NetBSD: Makefile,v 1.30 2015/08/18 07:31:10 wiz Exp $
#

DISTNAME=	open-cobol-1.1
PKGNAME=	opencobol-1.1
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=	rodo@bloerp.de
HOMEPAGE=	https://sourceforge.net/projects/open-cobol/
COMMENT=	Open-source COBOL compiler

CONFLICTS=		opensource-cobol-[0-9]* open-cobol-ce-[0-9]*

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

# Should be more cintelligent, forks only for NetBSD.
SUBST_CLASSES+=		bdb
SUBST_MESSAGE.bdb=	Fixing runtime error.
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	configure
SUBST_SED.bdb=		-e 's,db-4.5,db5,g'
SUBST_SED.bdb+=		-e 's,db-4.4,db4,g'
SUBST_SED.bdb+=		-e 's,ncurses,curses,g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
