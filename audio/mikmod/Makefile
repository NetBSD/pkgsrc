# $NetBSD: Makefile,v 1.10 1998/06/18 16:15:10 agc Exp $
#

DISTNAME=	mikmod-2.14-unix
PKGNAME=	mikmod-2.14
CATEGORIES=	audio
MASTER_SITES=	http://www.chiark.greenend.org.uk/~stevem/mikmod/

MAINTAINER=	mycroft@NetBSD.ORG

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

RESTRICTED=	"Registration required for redistribution and commercial use."
MIRROR_DISTFILE=	no

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}/source

do-install:
	( cd ${WRKSRC} ; ${INSTALL_PROGRAM} mikmod mikcvt ${PREFIX}/bin )
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/mikmod.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mikmod
.for f in  credits.txt mikmod.txt register.frm
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/$f ${PREFIX}/share/doc/mikmod
.endfor
.endif

.include "../../mk/bsd.pkg.mk"
