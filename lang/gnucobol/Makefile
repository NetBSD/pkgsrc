# $NetBSD: Makefile,v 1.5 2017/01/05 15:36:24 roy Exp $
#

DISTNAME=	gnu-cobol-2.0_rc-1
PKGNAME=	opencobol-2.0rc1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=	rodo@bloerp.de
HOMEPAGE=	https://sourceforge.net/projects/open-cobol/
COMMENT=	Open-source COBOL compiler
LICENSE=	gnu-gpl-v3

CONFLICTS=		opensource-cobol-[0-9]* open-cobol-ce-[0-9]*

WRKSRC=		${WRKDIR}/gnu-cobol-2.0

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db
CONFIGURE_ARGS+=	--with-lfs
CONFIGURE_ARGS+=	--without-readline
INFO_FILES=		yes

CONFIGURE_ENV+=		cobdb=${BDB_TYPE}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
