# $NetBSD: Makefile,v 1.29 1999/09/01 18:02:48 tron Exp $

DISTNAME=	mutt-${MUTT_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.guug.de/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.uib.no/pub/mutt/

MAINTAINER=	tron@netbsd.org
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

MUTT_BASE_VERSION=	1.0pre2
.if defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES
MUTT_VERSION=		${MUTT_BASE_VERSION}i

MIRROR_DISTFILE=	no
RESTRICTED=		"Contains PGP code"
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$//}
.else
MUTT_VERSION=		${MUTT_BASE_VERSION}

WRKSRC=			${WRKDIR}/${DISTNAME}-us
.endif
