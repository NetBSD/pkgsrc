# $NetBSD: Makefile,v 1.19 1999/02/20 22:48:34 hubertf Exp $

DISTNAME=	mutt-${MUTT_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.guug.de/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.uib.no/pub/mutt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-curses=${PREFIX} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt
CONFIGURE_ENV+=	LDFLAGS=-s

.include "../../mk/bsd.pkg.mk"

MUTT_BASE_VERSION=	0.95.3
.if defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES
MUTT_VERSION=		${MUTT_BASE_VERSION}i

MIRROR_DISTFILE=	no
RESTRICTED=		"Contains PGP code"
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$//}
.else
MUTT_VERSION=		${MUTT_BASE_VERSION}

WRKSRC=			${WRKDIR}/${DISTNAME}-us
.endif
