# $NetBSD: Makefile,v 1.2 2008/03/03 17:45:35 jlam Exp $
#

DISTNAME=	etrace-2.1
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/etrace/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://ndevilla.free.fr/etrace/
COMMENT=	Function call tracing

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl

NO_BUILD=	yes

SHAREDIR=	${PREFIX}/share/etrace
DOCDIR=		${PREFIX}/share/doc/etrace
EXAMPLEDIR=	${PREFIX}/share/examples/etrace
BINDIR=		${PREFIX}/bin

INSTALLATION_DIRS=	bin

REPLACE_PERL=	src/etrace.pl
# python script uses /usr/bin/env; let it slide pending wondering if
# we really want to depend on python and use a pyNN- prefix.

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace ${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace.pl ${DESTDIR}${BINDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/ptrace.c ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${DESTDIR}${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
