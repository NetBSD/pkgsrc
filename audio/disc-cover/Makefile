# $NetBSD: Makefile,v 1.5 2002/08/31 03:38:44 wiz Exp $
#

DISTNAME=	disc-cover-1.3.2
CATEGORIES=	audio
MASTER_SITES=	http://home.wanadoo.nl/~jano/files/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://home.wanadoo.nl/~jano/disc-cover.html
COMMENT=	generation of CD covers

DEPENDS+=	p5-Audio-CD-0.05:../../audio/p5-Audio-CD

USE_BUILDLINK2=		YES
NO_BUILD=		YES
REPLACE_PERL=		disc-cover

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/disc-cover ${PREFIX}/bin

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
