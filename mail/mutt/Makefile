# $NetBSD: Makefile,v 1.14 1998/08/20 15:17:10 tsarna Exp $

DISTNAME=	mutt-0.93.2i
CATEGORIES=	mail
MASTER_SITES=	ftp://riemann.iam.uni-bonn.de/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mutt.org/

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

CONFLICTS=	mutt-0.89.1i mutt-0.91i mutt-0.91.1i mutt-0.93i mutt-0.93.1i

RESTRICTED=	"Contains PGP code"
MIRROR_DISTFILE= no
NO_PATCH=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-curses=${PREFIX} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt
CONFIGURE_ENV+=	LDFLAGS=-s

.include "../../mk/bsd.pkg.mk"
