# $NetBSD: Makefile,v 1.9 2019/07/10 17:53:38 sevan Exp $

DISTNAME=	opensource-cobol-1.5.1J-utf8
PKGNAME=	${DISTNAME:S/-utf8//}
CATEGORIES=	lang
MASTER_SITES=	-https://www.osscons.jp/osscobol/files/?action=cabinet_action_main_download&block_id=414&room_id=21&cabinet_id=11&file_id=382&upload_id=761

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.osscons.jp/osscobol/
COMMENT=	UTF-8 version of opensource COBOL, OpenCOBOL with Japanese extensions
LICENSE=	gnu-gpl-v2

CONFLICTS=		opencobol-[0-9]* open-cobol-ce-[0-9]*

BDB_ACCEPTED=		db4

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_FEATURES+=		strnlen

CONFIGURE_ARGS+=	--enable-utf8

TEST_TARGET=		check

#BUILDLINK_TRANSFORM+=	l:db:db4

# XXX This SUBST will work for NetBSD. Be more intelligent.
SUBST_CLASSES+=		bdb
SUBST_MESSAGE.bdb=	Fixing runrime error.
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	configure
SUBST_SED.bdb=		-e 's,db-4.4,db4,g'
SUBST_SED.bdb+=		-e 's,ncurses,curses,g'

INFO_FILES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
