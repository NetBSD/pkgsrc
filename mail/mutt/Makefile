# $NetBSD: Makefile,v 1.7 1998/04/22 14:22:44 agc Exp $

DISTNAME=	mutt-0.91.1i
CATEGORIES=	mail
MASTER_SITES=	ftp://riemann.iam.uni-bonn.de/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

RESTRICTED=	"Uses PGP"
MIRROR_DISTFILE= no
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-curses=${PREFIX}
CONFIGURE_ENV+=	LDFLAGS=-s

MAN1=		mutt.1

post-install:
	${MKDIR} ${PREFIX}/share/doc/mutt
	${CP} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/mutt
	${CP} ${WRKSRC}/doc/pgp-Notes.txt ${PREFIX}/share/doc/mutt

.include "../../mk/bsd.pkg.mk"
