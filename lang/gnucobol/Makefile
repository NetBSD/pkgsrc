# $NetBSD: Makefile,v 1.15 2024/05/29 16:33:13 adam Exp $
#

DISTNAME=	gnucobol-3.2
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gnucobol/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnucobol.sourceforge.io/
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
INFO_FILES=		yes
TEST_TARGET=		check

SUBST_CLASSES+=		bdb
SUBST_MESSAGE.bdb=	Detect pkgsrc Berkeley DB library
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	configure
SUBST_SED.bdb=		-e 's,db-$$COB_BDB_HEADER,${BDB_TYPE},g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
