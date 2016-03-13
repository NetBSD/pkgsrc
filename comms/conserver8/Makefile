# $NetBSD: Makefile,v 1.18 2016/03/13 18:31:11 schnoebe Exp $
#

PKGVER=		8.2.1
DISTNAME=	conserver-${PKGVER}
PKGNAME=	conserver8-${PKGVER}
CATEGORIES=	comms
MASTER_SITES=	http://www.conserver.com/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://www.conserver.com/
COMMENT=	Application that allows multiple users to watch serial consoles
#LICENSE=	# modified-bsd and more (see LICENSE file)

CONFLICTS=	conserver-[0-9]*

INSTALLATION_DIRS=	${EGDIR} ${DOCDIR}

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-master=${CONSERVER_DEFAULTHOST:Q}
CONFIGURE_ARGS+=	--with-port=${CONSERVER_DEFAULTPORT:Q}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-logfile=${VARBASE:Q}/log/conserver

.include "options.mk"

BUILD_DEFS+=	CONSERVER_DEFAULTPORT CONSERVER_DEFAULTHOST VARBASE

RCD_SCRIPTS=	conserver8

TEST_TARGET=	test

DOCDIR=		${PREFIX}/share/doc/conserver
EGDIR=		${PREFIX}/share/examples/conserver
CONF_FILES=	${EGDIR}/conserver.cf ${PKG_SYSCONFDIR}/conserver.cf
CONF_FILES+=	${EGDIR}/conserver.passwd ${PKG_SYSCONFDIR}/conserver.passwd
OWN_DIRS=	${VARBASE}/consoles

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	conserver.cf/conserver.cf
SUBST_SED.conf=		-e "s,/var/consoles,${VARBASE}/consoles,"

post-install:
	set -e; for File in INSTALL README PROTOCOL; do			\
	    ${INSTALL_DATA} ${WRKSRC}/$${File} ${DESTDIR}${DOCDIR}/$${File};\
	done
	set -e; for F in ${WRKSRC}/conserver.cf/samples/* ; do \
	    ${INSTALL_DATA} $$F ${DESTDIR}$EGDIR}; \
	done

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
