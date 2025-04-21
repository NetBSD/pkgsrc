# $NetBSD: Makefile,v 1.42 2025/04/21 16:22:09 wiz Exp $

DISTNAME=	bonnie
PKGNAME=	bonnie-2.06
PKGREVISION=	3
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.textuality.com/bonnie/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.textuality.com/bonnie/index.html
COMMENT=	Performance Test of Sequential Filesystem I/O and STDIO

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

USE_TOOLS+=		expr groff nroff
USE_BSD_MAKEFILE=	yes
MANCOMPRESSED_IF_MANZ=	yes

CFLAGS.Linux+=	-D_FILE_OFFSET_BITS=64
CFLAGS.SunOS+=	-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

post-extract:
	${MV} ${WRKSRC}/Bonnie.c ${WRKSRC}/bonnie.c

SYSCTL?=	/sbin/sysctl

benchmark:
	@(cd ${WRKSRC}; ./bonnie -m nb$$(uname -r) -s $$(${EXPR} 4 \* $$(${SYSCTL} -n hw.physmem) / 1024 / 1024) | tee bonnie.out)

results:
	@${MKDIR} /tmp/benches/$$(domainname)
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/$$(domainname)/bonnie.$$(uname)-$$(uname -m)-$$(uname -r).$$(hostname)

.include "../../mk/bsd.pkg.mk"
