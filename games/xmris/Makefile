# $NetBSD: Makefile,v 1.14 2008/01/19 09:16:23 wiz Exp $

DISTNAME=		xmris.4.0.5
PKGNAME=		xmris-4.05
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.planetfall.pwp.blueyonder.co.uk/xmris/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.planetfall.pwp.blueyonder.co.uk/xmris/
COMMENT=		Version of the Mr Do video arcade game for X

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

post-patch:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile-pre
	@${SED} -e 's@XXXVARBASEXXX@${VARBASE}@g'	\
		< ${WRKSRC}/Imakefile-pre > ${WRKSRC}/Imakefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/xmris.man ${PREFIX}/${PKGMANDIR}/man6/xmris.6
	${LN} -fs xmris.6 ${PREFIX}/${PKGMANDIR}/man6/xmsit.6
	${INSTALL_MAN} ${WRKSRC}/xmred.man ${PREFIX}/${PKGMANDIR}/man6/xmred.6

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
