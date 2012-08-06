# $NetBSD: Makefile,v 1.24 2012/08/06 13:33:38 adam Exp $

.include "../../databases/openldap/Makefile.version"

DISTNAME=	openldap-${OPENLDAP_VERSION}
PKGNAME=	${DISTNAME:S/-/-doc-/}
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/ \
		http://ftp.openldap.org/pub/OpenLDAP/openldap-release/ \
		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/openldap-release/ \
		ftp://ftp.ntua.gr/mirror/OpenLDAP/openldap-release/ \
		ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/openldap-release/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/openldap/openldap-release/ \
		ftp://ftp.nl.uu.net/pub/unix/db/openldap/openldap-release/ \
		ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/openldap-release/ \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.openldap.org/
COMMENT=	Lightweight Directory Access Protocol documentation
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
