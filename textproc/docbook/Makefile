# $NetBSD: Makefile,v 1.31 2005/02/18 16:09:15 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1998/06/27 05:19:35 asami Exp
#

DISTNAME=	docbook-4.4
CATEGORIES=	textproc
MASTER_SITES=		http://www.oasis-open.org/docbook/sgml/4.4/
SITES_docbook-4.3.zip=	http://www.oasis-open.org/docbook/sgml/4.3/
SITES_docbook-4.2.zip=	http://www.oasis-open.org/docbook/sgml/4.2/
SITES_docbk41.zip=	http://www.oasis-open.org/docbook/sgml/4.1/
SITES_docbk40.zip=	http://www.oasis-open.org/docbook/sgml/4.0/
SITES_docbk31.zip=	http://www.oasis-open.org/docbook/sgml/3.1/
SITES_docbk30.zip=	http://www.oasis-open.org/docbook/sgml/3.0/
SITES_docbk241.zip=	http://www.oasis-open.org/docbook/sgml/2.4.1/
DISTFILES=	docbk241.zip docbk30.zip docbk31.zip docbk40.zip docbk41.zip \
		docbook-4.2.zip docbook-4.3.zip docbook-4.4.zip

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.oasis-open.org/docbook
COMMENT=	SGML DTD designed for computer documentation

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	iso8879>=1986:../../textproc/iso8879

WRKSRC=		${WRKDIR}
NO_MTREE=       yes
USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
EXTRACT_ONLY=	# empty

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

SGML_CATALOGS=
.for ver in 2.4.1 3.0 3.1 4.0 4.1 4.2 4.3 4.4
SGML_CATALOGS+=	${INSTDIR}/${ver}/catalog
.endfor
.undef ver

do-build:
.for ver in 241 30 31 40 41 42 43 44
	${CP} ${FILESDIR}/catalog${ver} ${WRKDIR}
	${ECHO} "CATALOG \"${ISOCAT}\"" >> ${WRKDIR}/catalog${ver}
.endfor

pre-install:
	${INSTALL_DATA_DIR} ${INSTDIR}/2.4.1
	@[ -d ${INSTDIR}/3.0 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/3.0
	@[ -d ${INSTDIR}/3.1 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/3.1
	@[ -d ${INSTDIR}/4.0 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.0
	@[ -d ${INSTDIR}/4.1 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.1
	@[ -d ${INSTDIR}/4.2 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.2
	@[ -d ${INSTDIR}/4.3 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.3
	@[ -d ${INSTDIR}/4.4 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.4

do-install:
	#
	# 2.4.1:
	#
	@(cd ${INSTDIR}/2.4.1; unzip ${DISTDIR}/docbk241.zip)
	@${RM} -r ${INSTDIR}/2.4.1/iso-*
	@${INSTALL_DATA} ${WRKDIR}/catalog241 ${INSTDIR}/2.4.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/2.4.1/*
	#
	# 3.0:
	#
	@(cd ${INSTDIR}/3.0; unzip ${DISTDIR}/docbk30.zip)
	@${INSTALL_DATA} ${WRKDIR}/catalog30 ${INSTDIR}/3.0/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/3.0/*
	#
	# 3.1:
	#
	@(cd ${INSTDIR}/3.1; unzip ${DISTDIR}/docbk31.zip)
	@${INSTALL_DATA} ${WRKDIR}/catalog31 ${INSTDIR}/3.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/3.1/*
	#
	# 4.0:
	#
	@(cd ${INSTDIR}/4.0; unzip ${DISTDIR}/docbk40.zip)
	@${INSTALL_DATA} ${WRKDIR}/catalog40 ${INSTDIR}/4.0/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.0/*
	#
	# 4.1:
	#
	@(cd ${INSTDIR}/4.1; unzip ${DISTDIR}/docbk41.zip)
	@${INSTALL_DATA} ${WRKDIR}/catalog41 ${INSTDIR}/4.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.1/*
	#
	# 4.2:
	#
	@(cd ${INSTDIR}/4.2; unzip ${DISTDIR}/docbook-4.2.zip)
	@${INSTALL_DATA} ${WRKDIR}/catalog42 ${INSTDIR}/4.2/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.2/*
	#
	# 4.3:
	#
	@(cd ${INSTDIR}/4.3; unzip ${DISTDIR}/docbook-4.3.zip)
	@${INSTALL_DATA} ${WRKDIR}/catalog43 ${INSTDIR}/4.3/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.3/*
	#
	# 4.4:
	#
	@(cd ${INSTDIR}/4.4; unzip ${DISTDIR}/docbook-4.4.zip)
	@${INSTALL_DATA} ${WRKDIR}/catalog44 ${INSTDIR}/4.4/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.4/*
	#
	# General cleanup
	#
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
