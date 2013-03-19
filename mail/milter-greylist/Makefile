# $NetBSD: Makefile,v 1.61 2013/03/19 11:07:53 tron Exp $

DISTNAME=	milter-greylist-4.4.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for Sendmail and Postfix
LICENSE=	original-bsd

# yacc rule moving to y.tab.c and renaming
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
BUILD_TARGET=		milter-greylist

USE_TOOLS=		bison lex

RCD_SCRIPTS=		milter-greylist

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-conffile=${PKG_SYSCONFDIR:Q}/greylist.conf
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-user=${MILTER_USER}
BUILD_DEFS+=		MILTER_USER MILTER_GROUP VARBASE
FILES_SUBST+=		MILTER_USER=${MILTER_USER:Q}
FILES_SUBST+=		MILTER_GROUP=${MILTER_GROUP:Q}

INSTALLATION_DIRS+=	share/doc/milter-greylist
INSTALLATION_DIRS+=	share/examples/milter-greylist

OWN_DIRS_PERMS+=	${VARBASE}/milter-greylist ${MILTER_USER} ${MILTER_GROUP} 0755

SUBST_CLASSES+=         paths
SUBST_STAGE.paths=      pre-configure
SUBST_FILES.paths=      greylist.conf greylist2.conf
SUBST_SED.paths+=       -e "s|/var/run|${VARBASE}/run|g"
SUBST_SED.paths+=       -e "s|/var/milter-greylist|${VARBASE}/milter-greylist|g"
SUBST_MESSAGE.paths=    Fixing paths in conf examples.

EGDIR=                  ${PREFIX}/share/examples/milter-greylist
CONF_FILES=             ${EGDIR}/greylist.conf ${PKG_SYSCONFDIR}/greylist.conf


post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
	  ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${DESTDIR}${PREFIX}/share/examples/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist2.conf \
	  ${DESTDIR}${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
