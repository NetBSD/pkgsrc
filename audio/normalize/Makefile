# $NetBSD: Makefile,v 1.4 2002/12/02 22:17:36 jlam Exp $
#

DISTNAME=	normalize-0.7.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.cs.columbia.edu/~cvaill/normalize/
COMMENT=	Wave (.wav) file volume normalizer

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--with-audiofile
CONFIGURE_ARGS+=	--with-mad

#.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
