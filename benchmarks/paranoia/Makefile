# $NetBSD: Makefile,v 1.20.8.1 2013/07/17 12:42:04 gdt Exp $

DISTNAME=		paranoia
PKGNAME=		paranoia-960101
PKGREVISION=		1
CATEGORIES=		benchmarks
MASTER_SITES=		${MASTER_SITE_NETLIB:=paranoia/}
EXTRACT_SUFX=		.c

# Not really the HOMEPAGE:
# HOMEPAGE=		http://people.sc.fsu.edu/~jburkardt/c_src/paranoia/paranoia.html
# An alteranative MASTER_SITE:
# http://people.sc.fsu.edu/~jburkardt/c_src/paranoia/paranoia.c

MAINTAINER=		gdt@NetBSD.org
COMMENT=		Highly paranoid test of IEEE 754 conformance

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

# The use of -ffloat-store in CFLAGS is controversial.  The point of
# the program is to test the compiler/machine environment, and
# therefore this Makefile should not set non-default flags.

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o paranoia paranoia.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/paranoia ${DESTDIR}${PREFIX}/bin

benchmark:
	@(cd ${WRKSRC}; ./paranoia < ${FILESDIR}/paranoia.run | tee paranoia.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/paranoia.out /tmp/benches/`domainname`/paranoia.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
