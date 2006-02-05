# $NetBSD: Makefile,v 1.2 2006/02/05 23:08:08 joerg Exp $
#

DISTNAME=	flite-1.3-release
PKGNAME=	${DISTNAME:S/-release//}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/flite-1.3/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.speech.cs.cmu.edu/flite/
COMMENT=	Small and fast run-time synthesis engine

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
