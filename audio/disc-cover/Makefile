# $NetBSD: Makefile,v 1.3 2001/11/26 10:00:36 jlam Exp $
#

DISTNAME=	disc-cover-1.2.2
CATEGORIES=	audio
MASTER_SITES=	http://www.liacs.nl/~jvhemert/disc-cover/download/unstable/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.liacs.nl/~jvhemert/disc-cover/
COMMENT=	generation of CD covers

DEPENDS+=	p5-Audio-CD-0.04-disc-cover-1.1.0:../../audio/p5-Audio-CD-disc-cover

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES
REPLACE_PERL=		disc-cover

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/disc-cover ${PREFIX}/bin

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
