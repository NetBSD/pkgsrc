# $NetBSD: Makefile,v 1.7 1998/04/20 11:56:20 frueauf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/26 23:09:14 jseger Exp
#

DISTNAME=       Bonnie
PKGNAME=	bonnie-1.0
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp.sunet.se/pub/benchmark/Bonnie/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	packages@netbsd.org

NO_CONFIGURE=	yes

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

post-extract:
	${MV} ${WRKSRC}/Bonnie.c ${WRKSRC}/bonnie.c

.include "../../mk/bsd.pkg.mk"
