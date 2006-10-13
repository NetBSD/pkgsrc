# $NetBSD: Makefile,v 1.1.1.1 2006/10/13 23:45:15 gdt Exp $
#

DISTNAME=	etrace-2.1
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/etrace/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://ndevilla.free.fr/etrace/
COMMENT=	Function call tracing

USE_TOOLS+=	perl

NO_BUILD=	yes

SHAREDIR=	${PREFIX}/share/etrace
DOCDIR=		${PREFIX}/share/doc/etrace
EXAMPLEDIR=	${PREFIX}/share/examples/etrace
BINDIR=		${PREFIX}/bin

REPLACE_PERL=	src/etrace.pl
# python script uses /usr/bin/env; let it slide pending wondering if
# we really want to depend on python and use a pyNN- prefix.

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace ${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace.pl ${BINDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/ptrace.c ${SHAREDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
