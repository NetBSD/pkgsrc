# $NetBSD: Makefile,v 1.6 2009/07/03 10:40:30 drochner Exp $

DISTNAME=	sipsak-0.9.6-1
PKGNAME=	${DISTNAME:S/-1//}
PKGREVISION=	3
CATEGORIES=	net comms
MASTER_SITES=	http://download.berlios.de/sipsak/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://sipsak.org/
COMMENT=	Sipsak is a command-line SIP testing utility

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/-1//}

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
