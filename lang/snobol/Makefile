# $NetBSD: Makefile,v 1.2 2001/02/06 18:13:51 wiz Exp $
#

DISTNAME=	snobol-0.99.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.snobol4.com/ \
		ftp://alpha.gnu.org/budne/snobol/
DISTFILES=	vanilla.zip snobol-0.99.4.tar.gz

MAINTAINER=	refling@comet.lbl.gov
HOMEPAGE=	http://people.ne.mediaone.net/philbudne/snobol.html

BUILD_DEPENDS=	unzip:../../archivers/unzip

EXTRACT_ONLY=	snobol-0.99.4.tar.gz

ALL_TARGET=	it

USE_CONFIGURE=	NO

do-install:
	@${CP} ${WRKSRC}/doc/head ${WRKSRC}/doc/tutorial
	@unzip -d ${WRKSRC} -joqqLC ${DISTDIR}/vanilla.zip pm.exe
	@unzip -p -opaaqqLC ${WRKSRC}/pm.exe >> ${WRKSRC}/doc/tutorial
	@${GZIP_CMD} ${WRKSRC}/doc/tutorial
	@${INSTALL_PROGRAM} ${WRKSRC}/xsnobol4 ${PREFIX}/bin/snobol4
	@${INSTALL_MAN} ${WRKSRC}/doc/snobol4.1 ${PREFIX}/man/man1
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
