# $NetBSD: Makefile,v 1.35 2005/05/12 17:53:29 kristerw Exp $

DISTNAME=		nhc98src-1.18.tar.gz
PKGNAME=		nhc98-1.18
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/
DISTFILES=		nhc98src-1.18.tar.gz \
			nhc98-1.18-library-interfaces.tar.gz

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/
COMMENT=		Portable Haskell 98 compiler

# Not yet ported to 64-bit machines
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64 *-*-x86_64

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

USE_GNU_TOOLS+=		make
BUILD_TARGET=		default

HARCH=			`${WRKSRC}/script/harch`
PLIST_SUBST+=		HARCH=${HARCH}

post-extract:
	@${FIND} ${WRKSRC}/docs -type d -name \*CVS\* -print | ${XARGS} ${RM} -rf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
