# $NetBSD: Makefile,v 1.21 1999/03/04 00:26:02 tron Exp $

DISTNAME=	mutt-${MUTT_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.guug.de/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.uib.no/pub/mutt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	automake:../../devel/automake
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-curses=${PREFIX} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt \
		 --enable-pop --enable-imap
CONFIGURE_ENV+=	LDFLAGS=-s

.include "../../mk/bsd.pkg.mk"

MUTT_BASE_VERSION=	0.95.4
.if defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES
MUTT_VERSION=		${MUTT_BASE_VERSION}i

MIRROR_DISTFILE=	no
RESTRICTED=		"Contains PGP code"
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$//}
.else
MUTT_VERSION=		${MUTT_BASE_VERSION}

WRKSRC=			${WRKDIR}/${DISTNAME}-us
.endif
