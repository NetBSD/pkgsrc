#
# New ports collection makefile for:	mutt
# Version required:			mutt-0.91i
# Date Created:				11 April 1998
# Whom:					tron
#
# $NetBSD: Makefile,v 1.3 1998/04/12 23:27:43 tron Exp $

DISTNAME=	mutt-0.91i
CATEGORIES=	mail
MASTER_SITES=	ftp://riemann.iam.uni-bonn.de/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/

MAINTAINER=	tron@netbsd.org

LIB_DEPENDS=	ncurses.3.4:${PORTSDIR}/devel/ncurses

RESTRICTED=	"Uses PGP"
MIRROR_DISTFILE= no
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-curses=${PREFIX}

MAN1=		mutt.1

post-install:
	strip ${PREFIX}/bin/mutt
	${MKDIR} ${PREFIX}/share/doc/mutt
	${CP} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/mutt
	${CP} ${WRKSRC}/doc/pgp-Notes.txt ${PREFIX}/share/doc/mutt

.include <bsd.port.mk>
