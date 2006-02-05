# $NetBSD: Makefile,v 1.16 2006/02/05 23:08:12 joerg Exp $
#

DISTNAME=	normalize-0.7.6
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www1.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www1.cs.columbia.edu/~cvaill/normalize/
COMMENT=	Wave (.wav) file volume normalizer

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--with-audiofile
CONFIGURE_ARGS+=	--with-mad

#.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
