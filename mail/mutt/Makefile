# $NetBSD: Makefile,v 1.71 2001/06/12 20:33:05 jlam Exp $

DISTNAME=	mutt-1.2.5i
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		ftp://ftp.uib.no/pub/mutt/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/
COMMENT=	text-based MIME mail client with PGP support

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake-1.4:../../devel/automake
BUILD_USES_MSGFMT=	yes

USE_LIBINTL=		YES
CPPFLAGS+=		-I${LOCALBASE}/include
LIBS=			-lintl
MAKE_ENV+=		LIBS="${LIBS}"
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

.include "../../mk/bsd.pkg.mk"
