# $NetBSD: Makefile,v 1.2 2001/07/31 13:54:35 drochner Exp $
#

DISTNAME=	disc-cover-1.2.2
CATEGORIES=	audio
MASTER_SITES=	http://www.liacs.nl/~jvhemert/disc-cover/download/unstable/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.liacs.nl/~jvhemert/disc-cover/
COMMENT=	generation of CD covers

DEPENDS+=	p5-Audio-CD-0.04-disc-cover-1.1.0:../../audio/p5-Audio-CD-disc-cover

USE_PERL5=	yes

EVAL_PREFIX+=	PERLPREFIX=perl

post-patch:
	${SED} "s@XXXPERLPREFIXXXX@${PERLPREFIX}@" <${WRKSRC}/disc-cover >${WRKSRC}/disc-cover.tmp && ${MV} ${WRKSRC}/disc-cover.tmp ${WRKSRC}/disc-cover

do-build:
	#nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/disc-cover ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
