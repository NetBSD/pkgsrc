# $NetBSD: Makefile,v 1.20 2022/06/28 11:31:42 wiz Exp $
#

DISTNAME=	etrace-2.1
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/etrace/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ndevilla.free.fr/etrace/
COMMENT=	Function call tracing

USE_TOOLS+=	perl:run

NO_BUILD=	yes

SHAREDIR=	${PREFIX}/share/etrace
DOCDIR=		${PREFIX}/share/doc/etrace
EXAMPLEDIR=	${PREFIX}/share/examples/etrace
BINDIR=		${PREFIX}/bin

AUTO_MKDIRS=	yes

REPLACE_PERL=	src/etrace.pl
REPLACE_PYTHON=	src/etrace

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace ${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/etrace.pl ${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/ptrace.c ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${DESTDIR}${EXAMPLEDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
