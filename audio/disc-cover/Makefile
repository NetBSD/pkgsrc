# $NetBSD: Makefile,v 1.12 2003/12/05 15:15:59 drochner Exp $
#

DISTNAME=	disc-cover-1.5.4
CATEGORIES=	audio
MASTER_SITES=	http://homepages.cwi.nl/~jvhemert/files/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://homepages.cwi.nl/~jvhemert/disc-cover.html
COMMENT=	Generation of CD covers

DEPENDS+=	p5-Audio-CD-0.05:../../audio/p5-Audio-CD

USE_BUILDLINK2=		YES
REPLACE_PERL=		disc-cover

DCTMPL=	${PREFIX}/share/disc-cover/templates

do-build:
	cd ${WRKSRC} && ${BUILDLINK_PREFIX.perl}/bin/pod2man \
		disc-cover > disc-cover.1
	${SED} "s|@DCTMPL@|${DCTMPL}|g" <${WRKSRC}/disc-cover \
		>${WRKDIR}/disc-cover

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/disc-cover ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/disc-cover.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${DCTMPL}
	${INSTALL_DATA} ${WRKSRC}/templates/* ${DCTMPL}

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
