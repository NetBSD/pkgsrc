# $NetBSD: Makefile,v 1.4 2002/11/21 05:08:52 salo Exp $
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

USE_BUILDLINK2=		YES
AUTOMAKE_REQD=		1.4
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/common/mp4v2/libtool

pre-configure:
	for dir in . common/mp4v2 ; do					\
		cd ${WRKSRC}/$$dir;					\
		${ACLOCAL} -I .;					\
		${AUTOHEADER};						\
		${LOCALBASE}/bin/libtoolize --automake;			\
		${AUTOMAKE} --add-missing;				\
		${AUTOCONF};						\
	done

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
post-configure:
	${CP} ${WRKSRC}/common/faad/getopt.* ${WRKSRC}/frontend
	${CP} ${WRKSRC}/frontend/Makefile ${WRKSRC}/frontend/Makefile.orig
	${SED} -e "s|^faad_SOURCES.*|& getopt.c|" \
	       -e "s|^faad_OBJECTS.*|& getopt.$$(OBJEXT)|" \
	${WRKSRC}/frontend/Makefile.orig > ${WRKSRC}/frontend/Makefile
.endif

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
