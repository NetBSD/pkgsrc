# $NetBSD: Makefile,v 1.6 2005/06/16 06:58:00 jlam Exp $
#

DISTNAME=       parrot-0.0.1
CATEGORIES=	lang
MASTER_SITES=	http://www.netthink.co.uk/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/parrot.html
COMMENT=	Bytecode language possibly to be used by Perl/Python

USE_PERL5=	# defined

BUILD_TARGET=	test_prog

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/include/parrot
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/parrot
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/parrot
	${INSTALL_PROGRAM} ${WRKSRC}/test_prog ${PREFIX}/bin/parrot
	${INSTALL_SCRIPT} ${WRKSRC}/assemble.pl ${PREFIX}/share/parrot
	${INSTALL_SCRIPT} ${WRKSRC}/disassemble.pl ${PREFIX}/share/parrot
	${INSTALL_SCRIPT} ${WRKSRC}/t/test*.pasm ${PREFIX}/share/parrot
	${INSTALL_DATA} ${WRKSRC}/opcode_table	${PREFIX}/include/parrot
	${INSTALL_DATA} ${WRKSRC}/interp_guts.h	${PREFIX}/include/parrot
	${INSTALL_DATA} ${WRKSRC}/README	${PREFIX}/share/doc/parrot
	${INSTALL_DATA} ${WRKSRC}/TODO	${PREFIX}/share/doc/parrot

.include "../../mk/bsd.pkg.mk"
