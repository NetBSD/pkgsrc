# $NetBSD: Makefile,v 1.26 2010/03/12 09:11:27 adam Exp $

DISTNAME=	sqlite-amalgamation-3.6.23
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

# Uses dlopen and friends but doesn't use -ldl on Linux.
# See http://www.sqlite.org/cvstrac/tktview?tn=3555
LIBS+=			${BUILDLINK_LDADD.dl}

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
