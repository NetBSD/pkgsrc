# $NetBSD: Makefile,v 1.2 2002/10/02 18:13:18 dillo Exp $
#

DISTNAME=	faad2-1.1
CATEGORIES=	audio
MASTER_SITES=	http://faac.sourceforge.net/files/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://faac.sourceforge.net/
COMMENT=	AAC decoding library


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
AUTOMAKE_REQD=	1.4

pre-configure:
	for dir in . common/mp4v2 ; do			\
		cd ${WRKSRC}/$$dir;			\
		${ACLOCAL} -I .;			\
		${AUTOHEADER};				\
		${LOCALBASE}/bin/libtoolize --automake;	\
		${AUTOMAKE} --add-missing;		\
		${AUTOCONF};				\
	done

.include "../../mk/automake.mk"
.include "../../audio/libsndfile/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
