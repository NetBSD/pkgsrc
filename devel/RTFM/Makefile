# $NetBSD: Makefile,v 1.5 2006/05/01 09:39:48 cube Exp $
#

DISTNAME=	RTFM-2.0.4
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.bestpractical.com/rtfm/
COMMENT=	Enterprise-grade knowledge management tool

DEPENDS+=	rt>=3.4.5:../../devel/rt3

.include "../../devel/rt3/dirs.mk"

PLIST_SUBST+=	RT_HTML_DIR=${RT_HTML_DIR:C/^${LOCALBASE}\///}	\
		RT_I18N_DIR=${RT_I18N_DIR:C/^${LOCALBASE}\///}

NO_BUILD=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	lib share

do-install:
	@${ECHO} "=> Libraries"
	cd ${WRKSRC}/lib/RT && ${FIND} . -type f ! -name '*.orig' 2>/dev/null |		\
		${PAX} -rw ${RT_LIB_DIR}/RT
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
