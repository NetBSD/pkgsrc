# $NetBSD: Makefile,v 1.1.1.1 2002/09/05 17:49:42 dillo Exp $
#

DISTNAME=	faad2-1.1
CATEGORIES=	audio
MASTER_SITES=	http://faac.sourceforge.net/files/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://faac.sourceforge.net/
COMMENT=	AAC decoding library

BUILD_DEPENDS+=autoconf-[0-9]*:../../devel/autoconf
BUILD_DEPENDS+=automake-[0-9]*:../../devel/automake

RESTRICTED=	Dolby doesn't allow binary distributions
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CD=	${RESTRICTED}

WRKSRC=		${WRKDIR}/faad2

USE_GMAKE=	YES
USE_LIBTOOL=    YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LIBTOOL_OVERRIDE=	${WRKSRC}/common/mp4v2/libtool
GNU_CONFIGURE=  YES
USE_BUILDLINK2=	YES

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
