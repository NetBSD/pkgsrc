# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:58 jmmv Exp $

DISTNAME=	lambdamoo-doc-1.8.0p6
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lambda.moo.mud.org/pub/MOO/ \
		ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=
DISTFILES=	ProgrammersManual.texinfo HelpSystem-02Jun93.txt

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ccs.neu.edu/home/eostrom/muds/lambdamoo.html
COMMENT=	documentation for lambdamoo

EXTRACT_CMD=	:

post-extract:
	${CP} ${DISTDIR}/ProgrammersManual.texinfo ${WRKSRC}

do-build:
	makeinfo --no-split --no-headers \
		${WRKSRC}/ProgrammersManual.texinfo \
		>${WRKSRC}/ProgrammersManual.txt

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lambdamoo
	${INSTALL_DATA} ${DISTDIR}/HelpSystem-02Jun93.txt \
		${PREFIX}/share/doc/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/ProgrammersManual.texinfo \
		${PREFIX}/share/doc/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/ProgrammersManual.txt \
		${PREFIX}/share/doc/lambdamoo

.include "../../mk/bsd.pkg.mk"
