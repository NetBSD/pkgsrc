# $NetBSD: Makefile,v 1.5 2012/10/08 09:57:21 asau Exp $
#

DISTNAME=	epm-4.2-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	misc
MASTER_SITES=	http://ftp.easysw.com/pub/epm/${VERSION}/ \
		http://ftp2.easysw.com/pub/epm/${VERSION}/ \
		http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/epm/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://epmhome.org/
COMMENT=	ESP generates software packages from a list of files
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		autoconf gzip:run tar:run

#TEST_TARGET=		test

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

DOCDIR=			${PREFIX}/share/doc/epm

CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--with-docdir=${DOCDIR}
CONFIGURE_ENV+=		STRIP=${TOOLS_PATH.strip}
CONFIGURE_ENV+=		GZIP=${TOOLS_PLATFORM.gzip:Q}

pre-configure:
	set -e; cd ${WRKSRC}; autoconf;
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/
	${CP} ${.CURDIR}/files/install-sh ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
