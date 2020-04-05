# $NetBSD: Makefile,v 1.5 2020/04/05 12:47:13 nia Exp $

DISTNAME=	libburn-1.5.2
#PKGNAME=	${DISTNAME:S/.pl/pl/}
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://libburnia-project.org/wiki/Libburn
COMMENT=	Library to write preformatted data onto optical media
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:C/.pl[0-9]*//}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libburn-1.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
