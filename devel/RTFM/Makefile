# $NetBSD: Makefile,v 1.2 2005/06/16 06:57:44 jlam Exp $
#

DISTNAME=	RTFM-2.0.4
CATEGORIES=	devel
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.bestpractical.com/rtfm/
COMMENT=	Enterprise-grade knowledge management tool

DEPENDS+=	p5-Text-WikiFormat>=0.72:../../textproc/p5-Text-WikiFormat
DEPENDS+=	rt>=3.2.1:../../devel/rt3

.include "../../mk/bsd.prefs.mk"

RT_LIB_DIR=	${LOCALBASE}/lib/rt3
RT_SITE_DIR=	${LOCALBASE}/share/rt3
RT_HTML_DIR=	${RT_SITE_DIR}/html
RT_I18N_DIR=	${RT_SITE_DIR}/local/po
BUILD_DEFS+=	RT_HTML_DIR RT_I18N_DIR

PLIST_SUBST+=	RT_HTML_DIR=${RT_HTML_DIR:C/^${LOCALBASE}\///}	\
		RT_I18N_DIR=${RT_I18N_DIR:C/^${LOCALBASE}\///}

NO_BUILD=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	lib share

do-install:
	@${ECHO} "=> Libraries"
	cd ${WRKSRC}/lib && ${FIND} . -type f ! -name '*.orig' 2>/dev/null |		\
		${PAX} -rw ${RT_LIB_DIR}
	@${ECHO} "=> HTML Documents"
	cd ${WRKSRC}/html && ${FIND} . -type f ! -name '*.orig' 2>/dev/null |		\
		${PAX} -rw ${RT_HTML_DIR}
	@${ECHO} "=> Locales"
	cd ${WRKSRC}/po && ${FIND} . -type f ! -name '*.orig' 2>/dev/null |		\
		${PAX} -rw ${RT_I18N_DIR}
	@${ECHO} "=> Database Schemas"
	${INSTALL_DATA_DIR} ${PREFIX}/share/RTFM
	for file in acl.Oracle acl.Pg acl.mysql schema.Oracle schema.Pg schema.mysql;	\
	do ${INSTALL_DATA} ${WRKSRC}/etc/$$file ${PREFIX}/share/RTFM; done

.include "../../mk/bsd.pkg.mk"
