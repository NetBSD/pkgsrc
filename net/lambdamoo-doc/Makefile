# $NetBSD: Makefile,v 1.12 2010/02/11 21:59:11 joerg Exp $

DISTNAME=	lambdamoo-doc-1.8.0p6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lambdamoo/} \
		ftp://ftp.kanga.nu/pub/mirrors/ftp.lambda.moo.mud.org/pub/MOO/
EXTRACT_SUFX=
DISTFILES=	ProgrammersManual.texinfo HelpSystem-02Jun93.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lambdamoo/
COMMENT=	Documentation for lambdamoo

PKG_DESTDIR_SUPPORT=	user-destdir

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
