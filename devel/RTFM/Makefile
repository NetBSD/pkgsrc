# $NetBSD: Makefile,v 1.9.2.1 2012/10/31 16:14:30 tron Exp $
#

DISTNAME=	RTFM-2.4.5
CATEGORIES=	devel
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bestpractical.com/rtfm/
COMMENT=	Enterprise-grade knowledge management tool

DEPENDS+=	rt>=3.4.5:../../devel/rt3

USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/rt3/dirs.mk"

PLIST_SUBST+=	RT_HTML_DIR=${RT_HTML_DIR:C/^${LOCALBASE}\///}	\
		RT_I18N_DIR=${RT_I18N_DIR:C/^${LOCALBASE}\///}

NO_BUILD=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	lib share

do-install:
	@${ECHO} "=> Libraries"
	${INSTALL_DATA_DIR} ${DESTDIR}${RT_LIB_DIR}
	cd ${WRKSRC}/lib/RT && ${FIND} . -type f ! -name '*.orig' 2>/dev/null |		\
		pax -rw ${DESTDIR}${RT_LIB_DIR}/RT
	@${ECHO} "=> HTML Documents"
	${INSTALL_DATA_DIR} ${DESTDIR}${RT_HTML_DIR}
	cd ${WRKSRC}/html && ${FIND} . -type f ! -name '*.orig' 2>/dev/null |		\
		pax -rw ${DESTDIR}${RT_HTML_DIR}
#	@${ECHO} "=> Locales"
#	${INSTALL_DATA_DIR} ${DESTDIR}${RT_I18N_DIR}
#	cd ${WRKSRC}/po && ${FIND} . -type f ! -name '*.orig' 2>/dev/null |		\
#		pax -rw ${DESTDIR}${RT_I18N_DIR}
	@${ECHO} "=> Database Schemas"
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/RTFM
	for file in acl.Oracle acl.Pg acl.mysql schema.Oracle schema.Pg schema.mysql;	\
	do ${INSTALL_DATA} ${WRKSRC}/etc/$$file ${DESTDIR}${PREFIX}/share/RTFM; done

.include "../../mk/bsd.pkg.mk"
