# $NetBSD: Makefile,v 1.27 2009/12/17 22:36:00 abs Exp $

DISTNAME=	ddclient-3.6.6
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ddclient/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ddclient.sourceforge.net/
COMMENT=	Client to update dynamic DNS entries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# empty

BUILD_DEFS+=		VARBASE
DOCDIR=			${PREFIX}/share/doc/ddclient
EGDIR=			${PREFIX}/share/examples/ddclient
RCD_SCRIPTS=		ddclient
CONF_FILES_PERMS=	${EGDIR}/sample-etc_ddclient.conf		\
			${PKG_SYSCONFDIR}/ddclient.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0600

INSTALLATION_DIRS=	sbin share/doc/ddclient share/examples/ddclient
PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.cisco ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-* ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
