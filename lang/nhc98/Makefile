# $NetBSD: Makefile,v 1.42 2012/08/14 17:07:57 asau Exp $

DISTNAME=		nhc98src-1.18.tar.gz
PKGNAME=		nhc98-1.18
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/
DISTFILES=		nhc98src-1.18.tar.gz \
			nhc98-1.18-library-interfaces.tar.gz

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/
COMMENT=		Portable Haskell 98 compiler

# Not yet ported to 64-bit machines
NOT_FOR_PLATFORM=	${LP64PLATFORMS}

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*-*

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX:Q} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

USE_TOOLS+=		gmake
BUILD_TARGET=		default

PLIST_SUBST+=		HARCH=`${WRKSRC}/script/harch`

post-extract:
	@${FIND} ${WRKSRC}/docs -type d -name \*CVS\* -print | ${XARGS} ${RM} -rf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
