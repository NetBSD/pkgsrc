# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:08 tv Exp $
#

DISTNAME=	normalize-0.7.6
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.columbia.edu/~cvaill/normalize/
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
