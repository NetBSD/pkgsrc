# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:15 tv Exp $
#

DISTNAME=		jabberd-2.0s3
PKGREVISION=	1
CATEGORIES=		chat
MASTER_SITES=		http://www.jabberstudio.org/files/jabberd2/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://jabberd.jabberstudio.org/2/
COMMENT=		Instant messaging server (version 2)

CONFLICTS=		jabberd-[0-9]*:../../chat/jabberd

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

BUILDLINK_DEPENDS.openssl+=	openssl>=0.9.6b
BUILDLINK_TRANSFORM.db4=	-e "s,/db4/,/,g"

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	configure
SUBST_MESSAGE.path=	"Fixing configure script."
SUBST_SED.path=		-e "s,/usr/local,${PREFIX},g"			\
			-e "s,\$sysconfdir/jabberd,\$sysconfdir,g"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-mysql
CONFIGURE_ARGS+=	--enable-pipe
CONFIGURE_ARGS+=	--enable-anon

REPLACE_PERL=		tools/*.pl

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	JABBERD_USER JABBERD_GROUP JABBERD_LOGDIR JABBERD_PIDDIR

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		jabberd c2s sm resolver router s2s
JABBERD_USER?=		jabberd
JABBERD_GROUP?=		jabberd
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER}
FILES_SUBST+=		JABBERD_GROUP=${JABBERD_GROUP}
FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR}
FILES_SUBST+=		JABBERD_LOGDIR=${JABBERD_LOGDIR}
PKG_GROUPS=             ${JABBERD_GROUP}
PKG_USERS=              ${JABBERD_USER}:${JABBERD_GROUP}

BINDIR=			${PREFIX}/bin
EGDIR=			${PREFIX}/share/examples/jabberd
SUPPORT_FILES=          ${EGDIR}/jabberd.cfg ${PKG_SYSCONFDIR}/jabberd.cfg

FILES=			c2s.xml resolver.xml router.xml			\
			router-users.xml s2s.xml sm.xml
DBFILES=		db-setup.mysql db-setup.pgsql

.for f in ${FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
CONF_FILES+=		${EGDIR}/roster.xml ${PKG_SYSCONFDIR}/roster.xml
.undef f

PKG_OPTIONS.jabberd2?=	mysql4

.include "options.mk"

.for f in ${JABBERD_LOGDIR} ${JABBERD_DBDIR} ${JABBERD_PIDDIR}
OWN_DIRS_PERMS+=	${f} ${JABBERD_USER} ${JABBERD_GROUP} 770
.endfor
.undef f

post-extract:
.for f in jabberd.cfg ${FILES}
	@${MV} ${WRKSRC}/etc/${f}.dist.in ${WRKSRC}/etc/${f}.in
.endfor
.undef f

pre-configure:
.for f in ${FILES} jabberd.cfg
	@${SED}								\
		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"		\
		-e "s|@PIDDIR@|${JABBERD_PIDDIR}|g"			\
		-e "s|@LOGDIR@|${JABBERD_LOGDIR}|g"			\
		-e "s|@SSLCERTS@|${SSLCERTS}|g"				\
		-e "s|@BINDIR@|${PREFIX}/bin|g"				\
		-e "s|@DBDIR@|${JABBERD_DBDIR}|g"			\
		${WRKSRC}/etc/${f}.in > ${WRKSRC}/etc/${f}
.endfor
.undef f

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/templates/roster.xml.dist.in	\
	    ${EGDIR}/roster.xml
	${INSTALL_SCRIPT} ${WRKSRC}/tools/pipe-auth.pl ${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/migrate.pl ${BINDIR}
.for f in ${DBFILES}
	${INSTALL_DATA} ${WRKSRC}/tools/${f} ${EGDIR}
.endfor
.undef f
.for f in jabberd.cfg ${FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${EGDIR}
.endfor
.undef f

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
