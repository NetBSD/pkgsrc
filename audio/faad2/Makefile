# $NetBSD: Makefile,v 1.16 2004/04/25 12:07:12 dillo Exp $
#

DISTNAME=	faad2-2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	tech-pkg@NetBSD.org
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

CONFIGURE_ARGS+=	--with-mp4v2
# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

pre-configure:
	${CP} ${WRKSRC}/common/faad/getopt.* ${WRKSRC}/frontend
	for dir in . ; do					\
		cd ${WRKSRC}/$$dir;					\
		${ACLOCAL} -I .;					\
		${AUTOHEADER};						\
		${LOCALBASE}/bin/libtoolize --automake;			\
		${AUTOMAKE} --add-missing;				\
		${AUTOCONF};						\
	done

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
