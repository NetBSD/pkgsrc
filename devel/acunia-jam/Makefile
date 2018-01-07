# $NetBSD: Makefile,v 1.18 2018/01/07 20:11:31 rillig Exp $
#

DISTNAME=	acunia-jam-1.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the program construction tool, like make(1)

CONFLICTS=	jam-[0-9]*

WRKSRC=		${WRKDIR}/jam
USE_TOOLS+=	yacc
AUTO_MKDIRS=	yes

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin.*/jam ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin.*/mkjambase ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} Porting README RELNOTES ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC} && ${INSTALL_DATA} *.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
