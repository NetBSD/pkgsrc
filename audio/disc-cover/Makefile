# $NetBSD: Makefile,v 1.7 2003/01/18 09:34:25 jmmv Exp $
#

DISTNAME=	disc-cover-1.4.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://home.wanadoo.nl/~jano/files/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://home.wanadoo.nl/~jano/disc-cover.html
COMMENT=	generation of CD covers

DEPENDS+=	p5-Audio-CD-0.05:../../audio/p5-Audio-CD

USE_BUILDLINK2=		YES
REPLACE_PERL=		disc-cover

do-build:
	cd ${WRKSRC} && ${BUILDLINK_PREFIX.perl}/bin/pod2man \
		disc-cover > disc-cover.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/disc-cover ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/disc-cover.1 ${PREFIX}/man/man1

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
