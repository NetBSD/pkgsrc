# $NetBSD: Makefile,v 1.14 2004/12/27 21:38:06 wiz Exp $
#

DISTNAME=	normalize-0.7.6
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www1.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www1.cs.columbia.edu/~cvaill/normalize/
COMMENT=	Wave (.wav) file volume normalizer

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--with-audiofile
CONFIGURE_ARGS+=	--with-mad

#.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
