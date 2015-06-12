# $NetBSD: Makefile,v 1.37 2015/06/12 10:50:40 wiz Exp $

DISTNAME=	ddclient-3.8.2
PKGREVISION=	2
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

REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		.*/bin/bash
REPLACE.sh.new=		/bin/sh
REPLACE_FILES.sh=	sample-ddclient-wrapper.sh
REPLACE_FILES.sh+=	sample-etc_rc.d_init.d_ddclient

INSTALLATION_DIRS=	sbin share/doc/ddclient share/examples/ddclient

do-configure:
	cd ${WRKSRC}; for f in ddclient; do				\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			-e "s|@VARBASE@|${VARBASE}|g"			\
			-e "s|@PERL5@|${PERL5}|g"			\
			$${f} > $${f}.fixed;			\
		if [ -x $${f} ]; then				\
			${CHMOD} +x $${f}.fixed;			\
		fi;							\
		${MV} -f $${f}.fixed $${f};			\
	done

do-build:	# empty

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
