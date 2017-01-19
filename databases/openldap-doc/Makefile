# $NetBSD: Makefile,v 1.27 2017/01/19 18:52:05 agc Exp $

.include "../../databases/openldap/Makefile.version"

DISTNAME=	openldap-${OPENLDAP_VERSION}
PKGNAME=	${DISTNAME:S/-/-doc-/}
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=	http://ftp.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=	ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/openldap-release/
MASTER_SITES+=	ftp://ftp.ntua.gr/mirror/OpenLDAP/openldap-release/
MASTER_SITES+=	ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/openldap-release/
MASTER_SITES+=	ftp://ftp.u-aizu.ac.jp/pub/net/openldap/openldap-release/
MASTER_SITES+=	ftp://ftp.nl.uu.net/pub/unix/db/openldap/openldap-release/
MASTER_SITES+=	ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/openldap-release/
MASTER_SITES+=	ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openldap.org/
COMMENT=	Lightweight Directory Access Protocol documentation
LICENSE=	modified-bsd

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			${PREFIX}/share/doc/openldap

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/admin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/guide.html ${DESTDIR}${DOCDIR}/admin/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/*.png ${DESTDIR}${DOCDIR}/admin/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/images/*.gif ${DESTDIR}${DOCDIR}/images/

.include "../../mk/bsd.pkg.mk"
