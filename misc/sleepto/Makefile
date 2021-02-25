# $NetBSD: Makefile,v 1.2 2021/02/25 10:28:22 simonb Exp $

DISTNAME=	sleepto-1.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	https://ftp.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/
COMMENT=	Sleep command with at-style time specification
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sleepto ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
