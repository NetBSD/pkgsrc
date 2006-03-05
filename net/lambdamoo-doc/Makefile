# $NetBSD: Makefile,v 1.10 2006/03/05 16:27:27 jlam Exp $

DISTNAME=	lambdamoo-doc-1.8.0p6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lambda.moo.mud.org/pub/MOO/ \
		ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=
DISTFILES=	ProgrammersManual.texinfo HelpSystem-02Jun93.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ccs.neu.edu/home/eostrom/muds/lambdamoo.html
COMMENT=	Documentation for lambdamoo

EXTRACT_ONLY=	ProgrammersManual.texinfo

WRKSRC=		${WRKDIR}
USE_TOOLS+=	makeinfo

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
