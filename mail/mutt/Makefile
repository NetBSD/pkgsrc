# $NetBSD: Makefile,v 1.35 2000/01/04 17:12:59 bouyer Exp $

DISTNAME=	mutt-${MUTT_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		ftp://ftp.uib.no/pub/mutt/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake
DEPENDS+=	ncurses-4.2:../../devel/ncurses

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+= --with-curses=${LOCALBASE} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt \
		 --enable-pop --enable-imap
LDFLAGS+=	-s

BUILD_DEFS+=	MUTT_INTERNATIONAL MUTT_VERSION


.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	LOCALEBASE=lib
.else
PLIST_SUBST+=	LOCALEBASE=share
.endif

MUTT_BASE_VERSION=	1.0
.if defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES
MUTT_VERSION=		${MUTT_BASE_VERSION}i

MIRROR_DISTFILE=	no
RESTRICTED=		"Contains PGP code"
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$//}
.else
MUTT_VERSION=		${MUTT_BASE_VERSION}

WRKSRC=			${WRKDIR}/${DISTNAME}-us
.endif
