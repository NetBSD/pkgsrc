# $NetBSD: Makefile,v 1.16.2.1 2004/07/26 07:40:04 agc Exp $

DISTNAME=	ddclient-3.6.2
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://burry.ca:4141/ddclient/
COMMENT=	Client to update dynamic DNS entries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

DOCDIR=			${PREFIX}/share/doc/ddclient
EGDIR=			${PREFIX}/share/examples/ddclient
RCD_SCRIPTS=		ddclient
CONF_FILES_PERMS=	${EGDIR}/sample-etc_ddclient.conf		\
			${PKG_SYSCONFDIR}/ddclient.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0600

INSTALLATION_DIRS=	sbin

do-configure:
	cd ${WRKSRC}; for file in ddclient; do				\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			-e "s|@PERL5@|${PERL5}|g"			\
			$${file} > $${file}.fixed;			\
		if [ -x $${file} ]; then				\
			${CHMOD} +x $${file}.fixed;			\
		fi;							\
		${MV} -f $${file}.fixed $${file};			\
	done

do-build:	# empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ddclient ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.cisco ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-* ${EGDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
