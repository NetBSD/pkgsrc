# $NetBSD: Makefile,v 1.35 2023/01/16 03:46:28 dholland Exp $
#

DISTNAME=	snobol4-1.3
PKGNAME=	snobol-1.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.snobol4.org/snobol/
MASTER_SITES+=	ftp://ftp.ultimate.com/snobol/
MASTER_SITES+=	ftp://ftp.snobol4.org/snobol/old/
MASTER_SITES+=	ftp://ftp.ultimate.com/snobol/old/
DIST_SUBDIR=	snobol4-1.3bis
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} vanilla.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snobol4.org/csnobol4/curr/
COMMENT=	Macro implementation of SNOBOL4 in C
LICENSE=	2-clause-bsd

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

SUBST_CLASSES+=			snobol-config
SUBST_STAGE.snobol-config=	pre-configure
SUBST_FILES.snobol-config=	Makefile
SUBST_SED.snobol-config+=	-e s\|M4=m4\|M4=${TOOLS_PATH.m4}\|

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
# not yet
#CONFIGURE_ARGS+=	--with-tcl
#CONFIGURE_ARGS+=	--with-tk

BUILD_TARGET=	all pv

USE_TOOLS+=		gzip m4 tar
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_JOBS_SAFE=		NO

post-build:
	${CP} ${WRKSRC}/doc/head ${WRKSRC}/doc/tutorial
	tar -Ozxf ${DISTDIR}/${DIST_SUBDIR}/vanilla.tar.gz vanilla/snobol4.man >> ${WRKSRC}/doc/tutorial
	${GZIP_CMD} ${WRKSRC}/doc/tutorial

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/snobol4
	cd ${WRKSRC} && ${INSTALL_DATA} README \
		${DESTDIR}${PREFIX}/share/doc/snobol4
	cd ${WRKSRC}/doc && ${INSTALL_DATA} load.txt design.txt tutorial.gz \
		${DESTDIR}${PREFIX}/share/doc/snobol4
	@${ECHO} ''
	@${ECHO} '***********************************************************'
	@${ECHO} '*  A helpful tutorial is at share/doc/snobol4/tutorial.gz *'
	@${ECHO} '*  within your package tree.                              *'
	@${ECHO} '***********************************************************'
	@${ECHO} ''

.include "../../mk/bsd.pkg.mk"
