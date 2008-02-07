# $NetBSD: Makefile,v 1.20 2008/02/07 13:24:36 tnn Exp $

DISTNAME=		bcc
PKGNAME=		bcc-95.3.12
CATEGORIES=		devel lang

MAINTAINER=		tsarna@NetBSD.org
COMMENT=		Bruce Evans' C compiler (with as and ld); can do 16-bit code

NOT_FOR_PLATFORM=	*-*-alpha *-*-x86_64	# Severe LP64 problems
NOT_FOR_PLATFORM+=	Interix-*-*		# no <a.out.h>

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	bin lib/bcc ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CPPFLAGS+=	-D_POSIX_SOURCE
.endif

post-extract:
	set -e; \
	cd ${FILESDIR}; \
	mkdir ${WRKSRC}/bcc-cc1; \
	cp Makefile.main ${WRKSRC}/Makefile; \
	cp Makefile.ld ${WRKSRC}/ld/Makefile; \
	cp ld86.1 ${WRKSRC}/ld/; \
	cp Makefile.as ${WRKSRC}/as/Makefile; \
	cp as86.1 ${WRKSRC}/as/; \
	cp Makefile.bcc ${WRKSRC}/bcc/Makefile; \
	cp bcc.1 ${WRKSRC}/bcc/; \
	cp Makefile.bcc-cc1 ${WRKSRC}/bcc-cc1/Makefile; \
	cp bcc-cc1.1 ${WRKSRC}/bcc-cc1/
	rm -f ${WRKSRC}/as/typeconv.o

.include "../../mk/bsd.pkg.mk"
