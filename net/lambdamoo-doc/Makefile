# $NetBSD: Makefile,v 1.15 2017/08/16 20:21:13 wiz Exp $

DISTNAME=	lambdamoo-doc-1.8.0p6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lambdamoo/}
MASTER_SITES+=	ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=
DISTFILES=	ProgrammersManual.texinfo HelpSystem-02Jun93.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lambdamoo/
COMMENT=	Documentation for lambdamoo

EXTRACT_ONLY=	ProgrammersManual.texinfo

WRKSRC=		${WRKDIR}
USE_TOOLS+=	makeinfo

do-build:
	makeinfo --no-split --no-headers \
		${WRKSRC}/ProgrammersManual.texinfo \
		>${WRKSRC}/ProgrammersManual.txt

INSTALLATION_DIRS+=	share/doc/lambdamoo

do-install:
	${INSTALL_DATA} ${DISTDIR}/HelpSystem-02Jun93.txt \
	    ${DESTDIR}${PREFIX}/share/doc/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/ProgrammersManual.texinfo \
	    ${DESTDIR}${PREFIX}/share/doc/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/ProgrammersManual.txt \
	    ${DESTDIR}${PREFIX}/share/doc/lambdamoo

.include "../../mk/bsd.pkg.mk"
