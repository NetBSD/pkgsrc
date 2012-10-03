# $NetBSD: Makefile,v 1.16 2012/10/03 00:20:10 asau Exp $

DISTNAME=	cn2jp1.4b
PKGNAME=	cn2jp-1.4b
PKGREVISION=	3
CATEGORIES=	converters
# maybe ftp://ftp.ifcss.org/pub/software/
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	rxg@NetBSD.org
# HOMEPAGE=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/
COMMENT=	Library for code translation between Chinese and Japanese

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/cn2jp
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin include lib share/doc/cn2jp

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cn2jp
	${INSTALL_DATA} ${WRKSRC}/lib/jp-util.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lang-util.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
