# $NetBSD: Makefile,v 1.2 1999/03/14 15:44:55 rh Exp $
# FreeBSD Id: Makefile,v 1.4 1998/06/27 05:19:35 asami Exp
#

DISTNAME=	docbook-3.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/davenport/ \
		ftp://ftp.wu-wien.ac.at/pub/sgml/davenport/
DISTFILES=	docbk241.tar.Z docbk30.tar.Z

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.ora.com/davenport/

DEPENDS+=	iso8879-1986:../../textproc/iso8879

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

pre-install:
	@[ -d ${INSTDIR}/2.4.1 ] || ${MKDIR} ${INSTDIR}/2.4.1
	@[ -d ${INSTDIR}/3.0 ] || ${MKDIR} ${INSTDIR}/3.0

do-install:
	@zcat ${DISTDIR}/docbk241.tar.Z |(cd ${INSTDIR}/2.4.1; pax -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog241 ${INSTDIR}/2.4.1/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/2.4.1/catalog
	@zcat ${DISTDIR}/docbk30.tar.Z |(cd ${INSTDIR}/3.0; pax -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog30 ${INSTDIR}/3.0/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.0/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/2.4.1/*
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/3.0/*
	@${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include "../../mk/bsd.pkg.mk"
