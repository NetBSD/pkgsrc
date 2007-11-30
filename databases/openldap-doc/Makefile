# $NetBSD: Makefile,v 1.7.2.1 2007/11/30 23:51:19 salo Exp $

DISTNAME=		openldap-2.3.39
PKGNAME=		${DISTNAME:S/-/-doc-/}
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=		http://ftp.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=		http://www.PlanetMirror.com/pub/openldap/openldap-release/
MASTER_SITES+=		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/openldap-release/
MASTER_SITES+=		ftp://ftp.matrix.com.br/pub/openldap/openldap-release/
MASTER_SITES+=		ftp://ftp.ucr.ac.cr/pub/Unix/openldap/openldap-release/
MASTER_SITES+=		ftp://ftp.ntua.gr/mirror/OpenLDAP/openldap-release/
MASTER_SITES+=		ftp://it.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=		ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/openldap-release/
MASTER_SITES+=		ftp://ftp.u-aizu.ac.jp/pub/net/openldap/openldap-release/
MASTER_SITES+=		ftp://ftp.holywar.net/pub/OpenLDAP/openldap-release/
MASTER_SITES+=		ftp://ftp.nl.uu.net/pub/unix/db/openldap/openldap-release/
MASTER_SITES+=		ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/openldap-release/
MASTER_SITES+=		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/openldap-release/
MASTER_SITES+=		ftp://ftp.plig.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.openldap.org/
COMMENT=		Lightweight Directory Access Protocol documentation

DISTINFO_FILE=		${.CURDIR}/../../databases/openldap/distinfo

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			${PREFIX}/share/doc/openldap
IMAGES=			config_dit.gif config_local.gif config_ref.gif
IMAGES+=		config_repl.gif config_x500fe.gif config_x500ref.gif
IMAGES+=		intro_dctree.gif intro_tree.gif replication.gif

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/admin
	${INSTALL_DATA_DIR} ${DOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/guide/COPYRIGHT ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/LICENSE ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/README ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/images/LDAPlogo.gif ${DOCDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/images/LDAPwww.gif ${DOCDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/guide.html ${DOCDIR}/admin/
.for file in ${IMAGES}
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/${file} ${DOCDIR}/admin/
.endfor

.include "../../mk/bsd.pkg.mk"
