# $NetBSD: Makefile,v 1.9 2014/01/06 22:11:01 joerg Exp $
#

DISTNAME=	flite-1.3-release
PKGNAME=	${DISTNAME:S/-release//}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/flite-1.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.speech.cs.cmu.edu/flite/
COMMENT=	Small and fast run-time synthesis engine

# Error opening output file '[...]/cmu_us_kal_diphone.o': No such file or directory
MAKE_JOBS_SAFE=	no

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
