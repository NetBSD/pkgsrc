# $NetBSD: Makefile,v 1.1.1.1 2001/02/12 18:34:38 tron Exp $

DISTNAME=	mutt-unstable-20010212
PKGNAME=	mutt-1.3.14.20010212i
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/snapshots/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	libiconv>=1.5:../../converters/libiconv

USE_LIBINTL=		YES
MAKE_ENV+=		CPPFLAGS=-I${LOCALBASE}/include LIBS=-lintl
CONFIGURE_ENV+=		LIBS=-lintl
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
CONFIGURE_SCRIPT=	./prepare
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh \
			--with-docdir=${PREFIX}/share/doc/mutt \
			--enable-pop --enable-imap \
			--without-included-gettext
USE_CURSES=		YES
REPLACE_NCURSES=	configure.in

LDFLAGS+=	${STRIPFLAG}
M4=		${LOCALBASE}/bin/gm4
WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}

.include "../../mk/bsd.prefs.mk"

.if defined(NEED_NCURSES) && ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+= --with-curses=${LOCALBASE}
.endif

MUTT_USE_SSL?=	YES

.if defined(MUTT_USE_SSL) && ${MUTT_USE_SSL} == "YES"
USE_SSL=	yes
CONFIGURE_ARGS+= --with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+= --without-ssl
.endif

BUILD_DEFS+=	MUTT_USE_SSL
PLIST_SUBST+=	LOCALEBASE=${LOCALEBASE}

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
