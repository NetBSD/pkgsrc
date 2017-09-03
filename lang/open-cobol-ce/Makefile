# $NetBSD: Makefile,v 1.3 2017/09/03 08:53:09 wiz Exp $

DISTNAME=	open-cobol-ce-1.1.r59
PKGNAME=	${DISTNAME:S/.r/./}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/open-cobol/
COMMENT=	OpenCOBOL CE compiler
LICENSE=	gnu-gpl-v2

CONFLICTS=		opencobol-[0-9]* opensource-cobol-[0-9]*

BDB_ACCEPTED=		db4

WRKSRC=			${WRKDIR}/open-cobol-ce-1.1
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

#BUILDLINK_TRANSFORM+=	l:db:db4

# XXX This SUBST will work for NetBSD. Be more intelligent.
SUBST_CLASSES+=		bdb
SUBST_MESSAGE.bdb=	Fixing runrime error.
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	configure
SUBST_SED.bdb=		-e 's,db-4.4,db4,g'
#SUBST_SED.bdb+=		-e 's,ncurses,curses,g'

TEST_TARGET=		check

INFO_FILES=		yes

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
