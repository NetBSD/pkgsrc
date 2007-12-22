# $NetBSD: Makefile,v 1.18 2007/12/22 21:40:13 tnn Exp $
#

DISTNAME=	snobol-0.99.4
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.snobol4.com/ \
		ftp://ftp.snobol4.org/snobol/old/
DISTFILES=	vanilla.zip ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snobol4.org/csnobol4/curr/
COMMENT=	Macro implementation of SNOBOL4 in C

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

BUILD_TARGET=	it

USE_CONFIGURE=		NO
USE_TOOLS+=		gzip
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_JOBS_SAFE=		NO

do-install:
	@${CP} ${WRKSRC}/doc/head ${WRKSRC}/doc/tutorial
	@unzip -d ${WRKSRC} -joqqLC ${DISTDIR}/vanilla.zip pm.exe
	@unzip -p -opaaqqLC ${WRKSRC}/pm.exe >> ${WRKSRC}/doc/tutorial
	@${GZIP_CMD} ${WRKSRC}/doc/tutorial
	@${INSTALL_PROGRAM} ${WRKSRC}/xsnobol4 ${PREFIX}/bin/snobol4
	@${INSTALL_MAN} ${WRKSRC}/doc/snobol4.1 ${PREFIX}/${PKGMANDIR}/man1
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/snobol4
	@cd ${WRKSRC} && ${INSTALL_DATA} snolib.a snolib/bq.sno \
		${PREFIX}/lib/snobol4
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snobol4
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} load.doc design.doc tutorial.gz \
		${PREFIX}/share/doc/snobol4
	@${ECHO} ''
	@${ECHO} '***********************************************************'
	@${ECHO} '*  A helpful tutorial is at share/doc/snobol4/tutorial.gz *'
	@${ECHO} '*  within your package tree.                              *'
	@${ECHO} '***********************************************************'
	@${ECHO} ''

.include "../../mk/bsd.pkg.mk"
