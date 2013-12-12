# $NetBSD: Makefile,v 1.88 2013/12/12 23:04:08 schnoebe Exp $

DISTNAME=	jabberd-2.3.1
CATEGORIES=	chat
MASTER_SITES=	https://github.com/jabberd2/jabberd2/releases/download/${DISTNAME}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://jabberd2.org/
COMMENT=	XMPP (Jabber) instant messaging server
LICENSE=	gnu-gpl-v2

CONFLICTS=		jabberd-[0-9]* sendfile-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-anon
CONFIGURE_ARGS+=	--enable-pipe
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-fs
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

# XXX force linking against pthread, so some modules do not fail to dlopen()
LDFLAGS+=	${PTHREAD_LDFLAGS}
LIBS+=		${PTHREAD_LIBS}

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

FILES=			jabberd.cfg c2s.xml router.xml router-users.xml \
			router-filter.xml s2s.xml sm.xml
DBFILES=		db-jd14-2-jd2.sql db-setup.mysql db-setup.pgsql \
			db-update.mysql	db-setup.sqlite db-update.sqlite
DOCFILES=		README.protocol README README.config NEWS

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
	sed	-e "s|@bindir@|${PREFIX}/bin|g"				\
		-e "s|@jabberd_router_bin@|router|g"			\
		-e "s|@jabberd_c2s_bin@|c2s|g"				\
		-e "s|@jabberd_s2s_bin@|s2s|g"				\
		-e "s|@jabberd_sm_bin@|sm|g"				\
		-e "s|@localstatedir@/@package@/db|${JABBERD_DBDIR}|g"	\
		-e "s|@localstatedir@/@package@/log|${JABBERD_LOGDIR}|g"	\
		-e "s|@localstatedir@/@package@/pid|${JABBERD_PIDDIR}|g"	\
		-e "s|@localstatedir@/@package@/run|${JABBERD_PIDDIR}|g"	\
		-e "s|@localstatedir@/@package@/stats|${JABBERD_LOGDIR}|g"\
		-e "s|@localstatedir@/lib/jabberd2|${JABBERD_DBDIR}|g"	\
		-e "s|@pkglibdir@|${PREFIX}/lib/jabberd|g"		\
		-e "s|<cachain>@sysconfdir@|<cachain>${SSLCERTS}|g"	\
		-e "s|<pemfile>@sysconfdir@|<pemfile>${SSLCERTS}|g"	\
		-e "s|cachain='@sysconfdir@|cachain='${SSLCERTS}|g"	\
		-e "s|pemfile='@sysconfdir@|pemfile='${SSLCERTS}|g"	\
		-e "s|@sysconfdir@/templates|${PKG_SYSCONFDIR}|g"	\
		-e "s|@sysconfdir@|${PKG_SYSCONFDIR}|g"			\
		${WRKSRC}/etc/${f}.in > ${WRKSRC}/etc/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/templates/roster.xml.dist.in	\
	    ${DESTDIR}${EGDIR}/roster.xml
	${INSTALL_SCRIPT} ${WRKSRC}/tools/bdbdump.pl ${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/pipe-auth.pl ${DESTDIR}${BINDIR}
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
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../net/udns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
