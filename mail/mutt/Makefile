# $NetBSD: Makefile,v 1.66 2001/02/13 11:47:02 tron Exp $

DISTNAME=	mutt-1.2.5i
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		ftp://ftp.uib.no/pub/mutt/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=	msgfmt:../../devel/gettext

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
REPLACE_NCURSES=	configure configure.in

LDFLAGS+=	${STRIPFLAG}
WRKSRC=		${WRKDIR}/${DISTNAME:S/i//}

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
PLIST_SUBST+=	LOCALEDIR=${LOCALEDIR}

.include "../../mk/bsd.pkg.mk"
