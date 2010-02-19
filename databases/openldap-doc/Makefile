# $NetBSD: Makefile,v 1.19 2010/02/19 20:49:29 ghen Exp $

DISTNAME=		openldap-2.4.21
PKGNAME=		${DISTNAME:S/-/-doc-/}
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=		http://ftp.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=		http://www.PlanetMirror.com/pub/openldap/openldap-release/
MASTER_SITES+=		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/openldap-release/
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

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../../databases/openldap/distinfo

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			${PREFIX}/share/doc/openldap
IMAGES=			allmail-en.png allusersgroup-en.png config_dit.png
IMAGES+=		config_local.png config_ref.png config_repl.png
IMAGES+=		dual_dc.png intro_dctree.png intro_tree.png
IMAGES+=		push-based-complete.png push-based-standalone.png
IMAGES+=		refint.png set-following-references.png
IMAGES+=		set-memberUid.png set-recursivegroup.png

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/admin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/guide/COPYRIGHT ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/LICENSE ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/README ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/images/LDAPlogo.gif ${DESTDIR}${DOCDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/images/LDAPwww.gif ${DESTDIR}${DOCDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/guide.html ${DESTDIR}${DOCDIR}/admin/
.for file in ${IMAGES}
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/${file} ${DESTDIR}${DOCDIR}/admin/
.endfor

.include "../../mk/bsd.pkg.mk"
