# $NetBSD: Makefile,v 1.47 2000/06/08 12:57:18 wiz Exp $

DISTNAME=	mutt-1.2i
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		ftp://ftp.uib.no/pub/mutt/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake

MIRROR_DISTFILE=no
RESTRICTED=	"Contains PGP and SSL code"

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+= --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt \
		 --enable-pop --enable-imap

ALL_TARGET=	keymap_defs.h all
LDFLAGS+=	-s
WRKSRC=		${WRKDIR}/${DISTNAME:S/i//}

.include "../../mk/bsd.prefs.mk"

MUTT_USE_SSL?=	YES

.if defined(MUTT_USE_SSL) && ${MUTT_USE_SSL} == "YES"
USE_SSL=	yes
CONFIGURE_ARGS+= --with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+= --without-ssl
.endif

BUILD_DEFS+=	MUTT_USE_SSL

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	LOCALEBASE=lib
.else
PLIST_SUBST+=	LOCALEBASE=share
.endif

.if ${OPSYS} == "NetBSD"
OSVER!=		uname -r
GOOD_CURSES=	1.4[Y-Z] 1.4Z[A-Z] 1.[5-9]*

.for PATTERN in ${GOOD_CURSES}
.if ${OSVER:M${PATTERN}} != ""
CURSES_GOOD?=	# defined
.endif
.endfor

.if !defined(CURSES_GOOD)
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
CONFIGURE_ARGS+= --with-curses=${LOCALBASE}
.endif
.endif

.include "../../mk/bsd.pkg.mk"
