# $NetBSD: Makefile,v 1.15 1998/12/12 17:21:04 tron Exp $

DISTNAME=	mutt-${MUTT_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://riemann.iam.uni-bonn.de/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

CONFLICTS=	mutt-*

NO_PATCH=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-curses=${PREFIX} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt
CONFIGURE_ENV+=	LDFLAGS=-s

.include "../../mk/bsd.pkg.mk"

MUTT_BASE_VERSION=	0.95
.if defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES
MUTT_VERSION=		${MUTT_BASE_VERSION}i

MIRROR_DISTFILE=	no
RESTRICTED=		"Contains PGP code"
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$//}
.else
MUTT_VERSION=		${MUTT_BASE_VERSION}

WRKSRC=			${WRKDIR}/${DISTNAME}-us
.endif
