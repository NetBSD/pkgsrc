# $NetBSD: Makefile,v 1.4 1998/05/09 15:24:44 frueauf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/30 03:18:07 asami Exp
#

DISTNAME=	bsddip-1.02
CATEGORIES=	net
#
# the actual master site is almost out of reach for everybody
#MASTER_SITES=	ftp://sun.rz.tu-clausthal.de/pub/bsddip/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	packages@netbsd.org

NO_CONFIGURE=	yes

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

.include <../../mk/bsd.pkg.mk>
