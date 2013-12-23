# $NetBSD: Makefile,v 1.45 2013/12/23 11:57:06 wiz Exp $

DISTNAME=	docbook-4.5
CATEGORIES=	textproc
MASTER_SITES=		http://www.oasis-open.org/docbook/sgml/4.5/
SITES.docbook-4.4.zip=	http://www.oasis-open.org/docbook/sgml/4.4/
SITES.docbook-4.3.zip=	http://www.oasis-open.org/docbook/sgml/4.3/
SITES.docbook-4.2.zip=	http://www.oasis-open.org/docbook/sgml/4.2/
SITES.docbk41.zip=	http://www.oasis-open.org/docbook/sgml/4.1/
SITES.docbk40.zip=	http://www.oasis-open.org/docbook/sgml/4.0/
SITES.docbk31.zip=	http://www.oasis-open.org/docbook/sgml/3.1/
SITES.docbk30.zip=	http://www.oasis-open.org/docbook/sgml/3.0/
SITES.docbk241.zip=	http://www.oasis-open.org/docbook/sgml/2.4.1/
DISTFILES=	docbk241.zip docbk30.zip docbk31.zip docbk40.zip docbk41.zip \
		docbook-4.2.zip docbook-4.3.zip docbook-4.4.zip docbook-4.5.zip

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oasis-open.org/docbook/
COMMENT=	SGML DTD designed for computer documentation

DEPENDS+=	iso8879>=1986:../../textproc/iso8879

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# none
USE_TOOLS+=		unzip
EXTRACT_ONLY=		# nothing

INSTDIR=		${DESTDIR}${PREFIX}/share/sgml/docbook
ISOCAT=			${PREFIX}/share/sgml/iso8879/catalog

SGML_CATALOGS=
.for ver in 2.4.1 3.0 3.1 4.0 4.1 4.2 4.3 4.4 4.5
SGML_CATALOGS+=	${PREFIX}/share/sgml/docbook/${ver}/catalog
.endfor

do-build:
.for ver in 241 30 31 40 41 42 43 44 45
	${CP} ${FILESDIR}/catalog${ver} ${WRKDIR}
	${CHMOD} +w ${WRKDIR}/catalog${ver}
	${ECHO} "CATALOG \"${ISOCAT}\"" >> ${WRKDIR}/catalog${ver}
.endfor

pre-install:
	${INSTALL_DATA_DIR} ${INSTDIR}/2.4.1
	[ -d ${INSTDIR}/3.0 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/3.0
	[ -d ${INSTDIR}/3.1 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/3.1
	[ -d ${INSTDIR}/4.0 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.0
	[ -d ${INSTDIR}/4.1 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.1
	[ -d ${INSTDIR}/4.2 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.2
	[ -d ${INSTDIR}/4.3 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.3
	[ -d ${INSTDIR}/4.4 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.4
	[ -d ${INSTDIR}/4.5 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.5

do-install:
.for ver in 2.4.1 3.0 3.1 4.0 4.1
	(cd ${INSTDIR}/${ver} && ${UNZIP_CMD} ${DISTDIR}/docbk${ver:S/.//g}.zip)
	${INSTALL_DATA} ${WRKDIR}/catalog${ver:S/.//g} ${INSTDIR}/${ver}/catalog
	${CHMOD} ${SHAREMODE} ${INSTDIR}/${ver}/*
.endfor
.for ver in 4.2 4.3 4.4 4.5
	(cd ${INSTDIR}/${ver} && ${UNZIP_CMD} ${DISTDIR}/docbook-${ver}.zip)
	${INSTALL_DATA} ${WRKDIR}/catalog${ver:S/.//g} ${INSTDIR}/${ver}/catalog
	${CHMOD} ${SHAREMODE} ${INSTDIR}/${ver}/*
.endfor
	${RM} -r ${INSTDIR}/2.4.1/iso-*
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
