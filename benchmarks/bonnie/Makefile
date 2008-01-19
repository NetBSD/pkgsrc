# $NetBSD: Makefile,v 1.32 2008/01/19 09:16:17 wiz Exp $

DISTNAME=	bonnie
PKGNAME=	bonnie-2.06
PKGREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.textuality.com/bonnie/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.textuality.com/bonnie/index.html
COMMENT=	Performance Test of Sequential Filesystem I/O and STDIO

NOT_FOR_PLATFORM=	Interix-*-* # has only 32-bit off_t

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

USE_TOOLS+=		expr
USE_BSD_MAKEFILE=	yes
MANCOMPRESSED_IF_MANZ=	yes

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
