# $NetBSD: Makefile,v 1.11 2006/12/27 13:37:37 joerg Exp $

DISTNAME=		xmris.4.0.5
PKGNAME=		xmris-4.05
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.planetfall.pwp.blueyonder.co.uk/xmris/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.planetfall.pwp.blueyonder.co.uk/xmris/
COMMENT=		Version of the Mr Do video arcade game for X

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile-pre
	@${SED} -e 's@XXXVARBASEXXX@${VARBASE}@g'	\
		< ${WRKSRC}/Imakefile-pre > ${WRKSRC}/Imakefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/xmris.man ${PREFIX}/man/man6/xmris.6
	${LN} -fs xmris.6 ${PREFIX}/man/man6/xmsit.6
	${INSTALL_MAN} ${WRKSRC}/xmred.man ${PREFIX}/man/man6/xmred.6

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
