# $NetBSD: Makefile,v 1.57 2010/06/02 13:14:47 adam Exp $

DISTNAME=	jabberd-2.2.9
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	http://codex.xiaoka.com/pub/jabberd2/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://jabberd2.xiaoka.com/
COMMENT=	XMPP (Jabber) instant messaging server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		jabberd-[0-9]*

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-anon
CONFIGURE_ARGS+=	--enable-pipe
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-fs
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.if (${MACHINE_ARCH} == alpha) || (${MACHINE_ARCH} == x86_64)
CONFIGURE_ARGS+=	CXXFLAGS=${CXXFLAGS:M*:C/-O./-Os/:M*:Q}
CONFIGURE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:C/-O./-Os/:M*:Q}
MAKE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:C/-O./-Os/:M*:Q}
CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:M*:C/-O./-Os/:M*:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:C/-O./-Os/:M*:Q}
MAKE_ENV+=		CFLAGS=${CFLAGS:M*:C/-O./-Os/:M*:Q}
.endif

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	configure
SUBST_MESSAGE.path=	Fixing configure script.
SUBST_SED.path=		-e "s,/usr/local,${PREFIX},g"
SUBST_SED.path+=	-e "s,\$$sysconfdir/jabberd,\$$sysconfdir,g"

REPLACE_PERL+=		tools/*.pl

.include "../../mk/bsd.prefs.mk"

JABBERD_DBDIR?=		${VARBASE}/db/jabberd

BUILD_DEFS+=		VARBASE JABBERD_USER JABBERD_GROUP
BUILD_DEFS+=		JABBERD_LOGDIR JABBERD_PIDDIR JABBERD_DBDIR

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		jabberd c2s sm router s2s
JABBERD_USER?=		jabberd
JABBERD_GROUP?=		jabberd
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER}
FILES_SUBST+=		JABBERD_GROUP=${JABBERD_GROUP}
FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR}
FILES_SUBST+=		JABBERD_LOGDIR=${JABBERD_LOGDIR}
PKG_USERS_VARS+=	JABBERD_USER
PKG_GROUPS_VARS+=	JABBERD_GROUP
PKG_GROUPS=		${JABBERD_GROUP}
PKG_USERS=		${JABBERD_USER}:${JABBERD_GROUP}

BINDIR=			${PREFIX}/bin
EGDIR=			${PREFIX}/share/examples/jabberd
DOCDIR=			${PREFIX}/share/doc/jabberd

FILES=			jabberd.cfg c2s.xml router.xml	\
			router-users.xml router-filter.xml s2s.xml	\
			sm.xml
DBFILES=		db-jd14-2-jd2.sql db-setup.mysql db-setup.pgsql \
			db-update.mysql	db-setup.sqlite db-update.sqlite
DOCFILES=		README.protocol README UPGRADE ChangeLog

INSTALLATION_DIRS=	bin ${EGDIR} ${DOCDIR}

.for f in ${FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
CONF_FILES+=		${EGDIR}/roster.xml ${PKG_SYSCONFDIR}/roster.xml

.include "options.mk"

.for f in ${JABBERD_LOGDIR} ${JABBERD_DBDIR} ${JABBERD_PIDDIR}
OWN_DIRS_PERMS+=	${f} ${JABBERD_USER} ${JABBERD_GROUP} 770
.endfor

post-extract:
.for f in ${FILES}
	mv ${WRKSRC}/etc/${f}.dist.in ${WRKSRC}/etc/${f}.in
.endfor

pre-configure:
.for f in ${FILES}
	sed	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"		\
		-e "s|@PIDDIR@|${JABBERD_PIDDIR}|g"			\
		-e "s|@LOGDIR@|${JABBERD_LOGDIR}|g"			\
		-e "s|@SSLCERTS@|${SSLCERTS}|g"				\
		-e "s|@BINDIR@|${PREFIX}/bin|g"				\
		-e "s|@DBDIR@|${JABBERD_DBDIR}|g"			\
		-e "s|@pkglibdir@|${PREFIX}/lib/jabberd|g"		\
		${WRKSRC}/etc/${f}.in > ${WRKSRC}/etc/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/templates/roster.xml.dist.in	\
	    ${DESTDIR}${EGDIR}/roster.xml
	${INSTALL_SCRIPT} ${WRKSRC}/tools/pipe-auth.pl ${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/migrate.pl ${DESTDIR}${BINDIR}
.for f in ${DBFILES}
	${INSTALL_DATA} ${WRKSRC}/tools/${f} ${DESTDIR}${EGDIR}
.endfor
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DESTDIR}${EGDIR}
.endfor
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../net/udns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
