# $NetBSD: Makefile,v 1.3 2009/02/14 10:34:56 rillig Exp $
#

DISTNAME=	etrace-2.1
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/etrace/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://ndevilla.free.fr/etrace/
COMMENT=	Function call tracing

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run

NO_BUILD=	yes

SHAREDIR=	${PREFIX}/share/etrace
DOCDIR=		${PREFIX}/share/doc/etrace
EXAMPLEDIR=	${PREFIX}/share/examples/etrace
BINDIR=		${PREFIX}/bin

AUTO_MKDIRS=	yes

REPLACE_PERL=	src/etrace.pl
# python script uses /usr/bin/env; let it slide pending wondering if
# we really want to depend on python and use a pyNN- prefix.

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace ${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace.pl ${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/ptrace.c ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${DESTDIR}${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
