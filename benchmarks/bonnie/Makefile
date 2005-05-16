# $NetBSD: Makefile,v 1.24 2005/05/16 04:38:03 jlam Exp $

DISTNAME=       bonnie
PKGNAME=	bonnie-2.06
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.textuality.com/bonnie/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.textuality.com/bonnie/index.html
COMMENT=	Performance Test of Sequential Filesystem I/O and STDIO

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

PKGSRC_USE_TOOLS+=	expr
MANCOMPRESSED_IF_MANZ=	yes

INSTALLATION_DIRS=	bin man/cat1 man/man1

post-extract:
	${MV} ${WRKSRC}/Bonnie.c ${WRKSRC}/bonnie.c

SYSCTL?=	/sbin/sysctl

benchmark:
	@(cd ${WRKSRC}; ./bonnie -m nb$$(uname -r) -s $$(${EXPR} 4 \* $$(${SYSCTL} -n hw.physmem) / 1024 / 1024) | tee bonnie.out)

results:
	@${MKDIR} /tmp/benches/$$(domainname)
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/$$(domainname)/bonnie.$$(uname)-$$(uname -m)-$$(uname -r).$$(hostname)

.include "../../mk/bsd.pkg.mk"
