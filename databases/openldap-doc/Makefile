# $NetBSD: Makefile,v 1.3 2006/08/25 07:02:28 ghen Exp $

DISTNAME=		openldap-2.3.27
PKGNAME=		${DISTNAME:S/-/-doc-/}
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
MASTER_SITES+=		http://ftp.openldap.org/pub/OpenLDAP/openldap-release/
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
