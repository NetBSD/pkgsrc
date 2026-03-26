# $NetBSD: Makefile,v 1.23 2026/03/26 00:15:57 gdt Exp $

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

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

# The point of the program is to test standard arithmetic.  However,
# operating systems may offer extended (non-standard!) precision by
# default.  Ask for IEEE754 compliance.
# \todo Validate that this flag is always ok, and if trouble
# conditionalize it.
CFLAGS+=	-fexcess-precision=standard

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
