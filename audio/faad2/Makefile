# $NetBSD: Makefile,v 1.14 2004/03/21 07:06:58 snj Exp $
#

DISTNAME=	faad2-1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://faac.sourceforge.net/
COMMENT=	AAC decoding library

RESTRICTED=	Dolby doesn't allow binary distributions
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}/faad2
USE_BUILDLINK3=		YES
USE_GCC_SHLIB=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

AUTOMAKE_REQD=		1.4
AUTOCONF_REQD=		2.50
GNU_CONFIGURE=		YES

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

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

.if ${OPSYS} == "SunOS"
post-configure:
	${CP} ${WRKSRC}/common/faad/getopt.* ${WRKSRC}/frontend
	${CP} ${WRKSRC}/frontend/Makefile ${WRKSRC}/frontend/Makefile.orig
	${SED} -e "s|^faad_SOURCES.*|& getopt.c|" \
	       -e "s|^faad_OBJECTS.*|& getopt.$$(OBJEXT)|" \
	${WRKSRC}/frontend/Makefile.orig > ${WRKSRC}/frontend/Makefile
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
