# $NetBSD: Makefile,v 1.7 2004/06/26 19:07:25 grant Exp $
#

DISTNAME=	john-1.6
PKGREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.openwall.com/john/

MAINTAINER=	DawS@irc.pl
HOMEPAGE=	http://www.openwall.com/john/
COMMENT=	Unix Password Cracker

WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	generic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../run/john ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/all.chr ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/alpha.chr ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/digits.chr ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/john.ini ${PREFIX}/share/john
	${INSTALL_DATA} ${WRKSRC}/../run/mailer ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../run/password.lst ${PREFIX}/share/john
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/unafs
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/unique
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/unshadow

.include "../../mk/bsd.pkg.mk"
