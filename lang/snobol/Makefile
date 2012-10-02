# $NetBSD: Makefile,v 1.25 2012/10/02 20:11:54 asau Exp $
#

DISTNAME=	snobol4-1.3
PKGNAME=	snobol-1.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.snobol4.org/snobol/ \
		ftp://ftp.ultimate.com/snobol/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} vanilla.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snobol4.org/csnobol4/curr/
COMMENT=	Macro implementation of SNOBOL4 in C
LICENSE=	2-clause-bsd

BROKEN=	Distfile doesn't match

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

SUBST_CLASSES+=			snobol-config
SUBST_STAGE.snobol-config=	post-patch
SUBST_FILES.snobol-config=	Makefile
SUBST_SED.snobol-config+=	-e s\|M4=m4\|M4=${TOOLS_PATH.m4:Q}\|

HAS_CONFIGURE=yes
CONFIGURE_ARGS+=--prefix=${PREFIX}
# not yet
#CONFIGURE_ARGS+=--with-tcl
#CONFIGURE_ARGS+=--with-tk

BUILD_TARGET=	all pv

USE_TOOLS+=		gzip m4 unzip
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_JOBS_SAFE=		NO

post-build:
	${CP} ${WRKSRC}/doc/head ${WRKSRC}/doc/tutorial
	unzip -d ${WRKSRC} -joqqLC ${DISTDIR}/vanilla.zip pm.exe
	unzip -p -opaaqqLC ${WRKSRC}/pm.exe >> ${WRKSRC}/doc/tutorial
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
