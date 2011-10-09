# $NetBSD: Makefile,v 1.2 2011/10/09 10:02:46 cheusov Exp $
#

VERSION=	4.2
DISTNAME=	epm-${VERSION}-source
PKGNAME=	epm-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://ftp.easysw.com/pub/epm/${VERSION}/ \
		http://ftp2.easysw.com/pub/epm/${VERSION}/ \
		http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/epm/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://epmhome.org/
COMMENT=	ESP generates software packages from a list of files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		autoconf #gzip:run tar:run

#TEST_TARGET=		test

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

DOCDIR=			${PREFIX}/share/doc/epm

CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--with-docdir=${DOCDIR}
CONFIGURE_ENV+=		STRIP=${TOOLS_PATH.strip}

pre-configure:
	set -e; cd ${WRKSRC}; autoconf;
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/
	${CP} ${.CURDIR}/files/install-sh ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
