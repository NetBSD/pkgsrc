# $NetBSD: Makefile,v 1.23 2003/11/15 02:16:31 danw Exp $
# FreeBSD Id: Makefile,v 1.4 1998/06/27 05:19:35 asami Exp
#

DISTNAME=	docbook-4.2
PKGREVISION=	3
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=		http://www.oasis-open.org/docbook/sgml/4.2/
SITES_docbk41.zip=	http://www.oasis-open.org/docbook/sgml/4.1/
SITES_docbk40.zip=	http://www.oasis-open.org/docbook/sgml/4.0/
SITES_docbk31.zip=	http://www.oasis-open.org/docbook/sgml/3.1/
SITES_docbk30.zip=	http://www.oasis-open.org/docbook/sgml/3.0/
SITES_docbk241.zip=	http://www.oasis-open.org/docbook/sgml/2.4.1/
DISTFILES=	docbk241.zip docbk30.zip docbk31.zip docbk40.zip docbk41.zip \
		docbook-4.2.zip

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.oasis-open.org/docbook
COMMENT=	SGML DTD designed for computer documentation

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	iso8879>=1986:../../textproc/iso8879

NO_MTREE=       yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

SGML_CATALOGS=
.for ver in 2.4.1 3.0 3.1 4.0 4.1 4.2
SGML_CATALOGS+=	${INSTDIR}/${ver}/catalog
.endfor
.undef ver

pre-install:
	${INSTALL_DATA_DIR} ${INSTDIR}/2.4.1
	@[ -d ${INSTDIR}/3.0 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/3.0
	@[ -d ${INSTDIR}/3.1 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/3.1
	@[ -d ${INSTDIR}/4.0 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.0
	@[ -d ${INSTDIR}/4.1 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.1
	@[ -d ${INSTDIR}/4.2 ] || ${INSTALL_DATA_DIR} ${INSTDIR}/4.2

do-install:
	#
	# 2.4.1:
	#
	@(cd ${INSTDIR}/2.4.1; unzip ${DISTDIR}/docbk241.zip)
	@${RM} -r ${INSTDIR}/2.4.1/iso-*
	@${INSTALL_DATA} ${FILESDIR}/catalog241 ${INSTDIR}/2.4.1/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/2.4.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/2.4.1/*
	#
	# 3.0:
	#
	@(cd ${INSTDIR}/3.0; unzip ${DISTDIR}/docbk30.zip)
	@${INSTALL_DATA} ${FILESDIR}/catalog30 ${INSTDIR}/3.0/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.0/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/3.0/*
	#
	# 3.1:
	#
	@(cd ${INSTDIR}/3.1; unzip ${DISTDIR}/docbk31.zip)
	@${INSTALL_DATA} ${FILESDIR}/catalog31 ${INSTDIR}/3.1/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/3.1/*
	#
	# 4.0:
	#
	@(cd ${INSTDIR}/4.0; unzip ${DISTDIR}/docbk40.zip)
	@${INSTALL_DATA} ${FILESDIR}/catalog40 ${INSTDIR}/4.0/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/4.0/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.0/*
	#
	# 4.1:
	#
	@(cd ${INSTDIR}/4.1; unzip ${DISTDIR}/docbk41.zip)
	@${INSTALL_DATA} ${FILESDIR}/catalog41 ${INSTDIR}/4.1/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/4.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.1/*
	#
	# 4.2:
	#
	@(cd ${INSTDIR}/4.2; unzip ${DISTDIR}/docbook-4.2.zip)
	@${INSTALL_DATA} ${FILESDIR}/catalog42 ${INSTDIR}/4.2/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/4.2/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.2/*
	#
	# General cleanup
	#
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
