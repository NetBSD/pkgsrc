# Makefile for:		mikmod
# Version required:	2.14
#
# $NetBSD: Makefile,v 1.6 1998/03/20 07:08:43 mycroft Exp $
#

DISTNAME=	mikmod-2.14-unix
PKGNAME=	mikmod-2.14
CATEGORIES=	audio
MASTER_SITES=	http://www.chiark.greenend.org.uk/~stevem/mikmod/

MAINTAINER=	mycroft@NetBSD.ORG

LIB_DEPENDS=	ncurses.3.4:${PORTSDIR}/devel/ncurses

RESTRICTED=	"Registration required for redistribution and commercial use."
MIRROR_DISTFILE=	no

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAN1=		mikmod.1

do-install:
	( cd ${WRKSRC} ; ${INSTALL_PROGRAM} mikmod mikcvt ${PREFIX}/bin )
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/mikmod.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mikmod
.for f in  credits.txt mikmod.txt register.frm
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/$f ${PREFIX}/share/doc/mikmod
.endfor
.endif

.include <bsd.port.mk>
