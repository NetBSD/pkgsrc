# $NetBSD: Makefile,v 1.8 1998/06/20 09:20:38 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/26 23:09:14 jseger Exp
#

DISTNAME=       Bonnie
PKGNAME=	bonnie-1.0
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp.sunet.se/pub/benchmark/Bonnie/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	packages@netbsd.org

NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

post-extract:
	${MV} ${WRKSRC}/Bonnie.c ${WRKSRC}/bonnie.c

.include "../../mk/bsd.pkg.mk"
