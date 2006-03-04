# $NetBSD: Makefile,v 1.17 2006/03/04 21:28:57 jlam Exp $
#

DISTNAME=	normalize-0.7.6
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www1.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
