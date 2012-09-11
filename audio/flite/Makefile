# $NetBSD: Makefile,v 1.8 2012/09/11 23:59:37 asau Exp $
#

DISTNAME=	flite-1.3-release
PKGNAME=	${DISTNAME:S/-release//}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/flite-1.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.speech.cs.cmu.edu/flite/
COMMENT=	Small and fast run-time synthesis engine

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
