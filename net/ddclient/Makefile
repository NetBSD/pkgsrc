# $NetBSD: Makefile,v 1.49 2020/03/20 11:58:05 nia Exp $

DISTNAME=	ddclient-3.8.3
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ddclient/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ddclient.sourceforge.net/
COMMENT=	Client to update dynamic DNS entries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# empty

BUILD_DEFS+=		VARBASE
DOCDIR=			${PREFIX}/share/doc/ddclient
EGDIR=			${PREFIX}/share/examples/ddclient
RCD_SCRIPTS=		ddclient
CONF_FILES_PERMS=	${EGDIR}/sample-etc_ddclient.conf		\
			${PKG_SYSCONFDIR}/ddclient.conf			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600

DEPENDS+=		p5-JSON-Any>=0.0:../../converters/p5-JSON-Any

REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		.*/bin/bash
REPLACE.sh.new=		/bin/sh
REPLACE_FILES.sh=	sample-ddclient-wrapper.sh
REPLACE_FILES.sh+=	sample-etc_rc.d_init.d_ddclient

INSTALLATION_DIRS=	sbin share/doc/ddclient share/examples/ddclient

SUBST_CLASSES+=		config
SUBST_MESSAGE.config=	Adjust variables: PKG_SYSCONFDIR VARBASE PERL5 (in patch-aa)
SUBST_FILES.config+=	ddclient
SUBST_STAGE.config=	post-patch
SUBST_VARS.config=	PKG_SYSCONFDIR VARBASE PERL5

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ddclient ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ssl ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.cisco ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-* ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
