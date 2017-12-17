# $NetBSD: Makefile,v 1.6 2017/12/17 04:54:15 ryoon Exp $
#

DISTNAME=	gnucobol-2.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=	rodo@bloerp.de
HOMEPAGE=	https://open-cobol.sourceforge.io/
COMMENT=	Open-source COBOL compiler
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

CONFLICTS=		opensource-cobol-[0-9]* open-cobol-ce-[0-9]*
CONFLICTS+=		opencobol-[0-9]*

CHECK_PORTABILITY_SKIP=	tests/testsuite

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db
CONFIGURE_ARGS+=	--with-lfs
CONFIGURE_ARGS+=	--without-readline
INFO_FILES=		yes

SUBST_CLASSES+=		bdb
SUBST_MESSAGE.bdb=	Detect pkgsrc Berkeley DB library
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	configure
SUBST_SED.bdb=		-e 's,db-$$COB_BDB_HEADER,${BDB_TYPE},g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
