# $NetBSD: Makefile,v 1.1.1.1 2001/06/03 06:49:59 tron Exp $

DISTNAME=		mutt-1.3.18i
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/pub/mutt/snapshots/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		text-based MIME mail client with PGP support

BUILD_USES_MSGFMT=	YES
BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake-1.4:../../devel/automake
DEPENDS+=		libiconv>=1.5:../../converters/libiconv

USE_LIBINTL=		YES
MAKE_ENV+=		CPPFLAGS=-I${LOCALBASE}/include LIBS=-lintl
CONFIGURE_ENV+=		LIBS=-lintl
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh \
			--with-docdir=${PREFIX}/share/doc/mutt \
			--enable-pop --enable-imap \
			--without-included-gettext
USE_CURSES=		YES
REPLACE_NCURSES=	configure.in

LDFLAGS+=		${STRIPFLAG}
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}

.include "../../mk/bsd.prefs.mk"

.if defined(NEED_NCURSES) && ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=	--with-curses=${LOCALBASE}
.endif

MUTT_USE_SSL?=		YES

.if defined(MUTT_USE_SSL) && ${MUTT_USE_SSL} == "YES"
USE_SSL=		YES
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

BUILD_DEFS+=		MUTT_USE_SSL

.include "../../mk/bsd.pkg.mk"
