# $NetBSD: Makefile,v 1.29 2016/02/25 12:12:47 jperkin Exp $

DISTNAME=		bcc
PKGREVISION=		1
PKGNAME=		bcc-95.3.12
CATEGORIES=		devel lang

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Bruce Evans' C compiler (with as and ld); can do 16-bit code

CONFLICTS=		bin86-[0-9]*
CONFLICTS+=		dev86-[0-9]*

NOT_FOR_PLATFORM=	Interix-*-*		# no <a.out.h>
# These platforms cannot build 32-on-64 binaries.
NOT_FOR_PLATFORM+=	*-*-alpha
NOT_FOR_PLATFORM+=	DragonFly-*-x86_64

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	bin lib/bcc ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

CWARNFLAGS.clang=	-Wno-error=logical-op-parentheses -Wno-error=array-bounds
MAKE_FLAGS+=	CWARNFLAGS.clang=${CWARNFLAGS.clang:Q}

.include "../../mk/bsd.prefs.mk"

# This package has LP64 issues, so must build as 32-bit binary.
.for P in ${LP64PLATFORMS}
.if ${MACHINE_PLATFORM:M${P}}
CFLAGS+=		-m32
LDFLAGS+=		-m32
.endif
.endfor

CPPFLAGS.DragonFly+=	-D_POSIX_SOURCE

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
