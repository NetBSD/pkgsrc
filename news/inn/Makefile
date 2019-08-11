# $NetBSD: Makefile,v 1.128 2019/08/11 13:22:33 wiz Exp $

DISTNAME=		inn-2.6.1
PKGREVISION=		3
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/
MASTER_SITES+=		ftp://ftp.fu-berlin.de/unix/news/inn/

MAINTAINER=		spz@NetBSD.org
HOMEPAGE=		http://www.isc.org/software/inn/
COMMENT=		The public release of InterNet News (INN)
LICENSE=		modified-bsd AND gnu-gpl-v2

CONFLICTS+=		libradius-[0-9]* nntpclnt-[0-9]*

.include "../../news/inn/Makefile.common"

BUILD_DEFS+=		INN_DATA_DIR
BUILD_DEFS+=		VARBASE

FILES_SUBST+=		INN_DATA_DIR=${INN_DATA_DIR}

BUILD_DEFS+=		INN_PATHBIN
FILES_SUBST+=		INN_PATHBIN=${PREFIX}/${INN_PATHBIN:Q}

MESSAGE_SUBST+=		INN_PATHBIN=${INN_PATHBIN:Q}

PLIST_SUBST+=		INN_PATHBIN=${INN_PATHBIN:Q}

PKG_SYSCONFSUBDIR=	inn

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${INN_PREFIX}
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-setgid-inews 				\
			--enable-largefiles				\
			--bindir=${PREFIX}/${INN_PATHBIN}		\
			--sbindir=${PREFIX}/${INN_PATHBIN}		\
			--sysconfdir=${PKG_SYSCONFDIR} 			\
			--with-openssl=${SSLBASE:Q}			\
			--with-doc-dir=${PREFIX}/share/doc/inn	 	\
			--with-control-dir=${PREFIX}/${INN_PATHBIN}/control \
			--with-filter-dir=${PREFIX}/${INN_PATHBIN}/filter \
			--with-tmp-dir=${INN_DATA_DIR}/tmp		\
			--with-db-dir=${INN_DATA_DIR}/db 		\
			--with-http-dir=${INN_DATA_DIR}/http		\
			--with-log-dir=${INN_DATA_DIR}/log 		\
			--with-run-dir=${INN_DATA_DIR}/run 		\
			--includedir=${PREFIX}/include 			\
			--with-spool-dir=${INN_SPOOL:Q}			\
			--with-news-user=${INN_USER}			\
			--with-news-group=${INN_GROUP}
CONFIGURE_ENV+=		_PATH_AWK=${TOOLS_AWK}
CONFIGURE_ENV+=		_PATH_EGREP=${TOOLS_EGREP}
CONFIGURE_ENV+=		_PATH_SED=${TOOLS_SED}
CONFIGURE_ENV+=		_PATH_SH=${TOOLS_SH}
CONFIGURE_ENV+=		_PATH_SORT=${TOOLS_SORT}
CONFIGURE_ENV+=		GZIP=${TOOLS_GZIP_CMD}
USE_TOOLS+=		awk egrep gzip perl:run sed sh sort yacc

LDFLAGS.SunOS+= -lsocket -lnsl

DEPENDS+=		p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=		p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=		gnupg-[0-9]*:../../security/gnupg

USERGROUP_PHASE=	pre-install
PKG_USERS_VARS+=	INN_USER
PKG_GROUPS_VARS+=	INN_GROUP

PKG_GROUPS+=		${INN_GROUP}
PKG_USERS+=		${INN_USER}:${INN_GROUP}
PKG_GECOS.${INN_USER}=	Internet\ News
PKG_HOME.${INN_USER}=	${INN_DATA_DIR}
PKG_SHELL.${INN_USER}=	${SH}

EXAMPLEDIR=		${PREFIX}/share/examples/inn
INN_DATADIRS=		log log/OLD run tmp db spool http
INN_SPOOLDIRS=		archive articles overview incoming incoming/bad	\
			outgoing uniover innfeed

INSTALLATION_DIRS+=	sbin
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EXAMPLEDIR}
INSTALLATION_DIRS+=	${EXAMPLEDIR}/filter

MAKE_DIRS+=		${PREFIX}/bin
MAKE_DIRS+=		${PREFIX}/sbin
MAKE_DIRS+=		${PREFIX}/lib

INN_DIRS+=		${PKG_SYSCONFDIR}
INN_DIRS+=		${INN_DATA_DIR}

OWN_DIRS+=		${PREFIX}/${INN_PATHBIN}
OWN_DIRS+=		${PREFIX}/${INN_PATHBIN}/filter
OWN_DIRS+=		${EXAMPLEDIR}

.for dir in ${INN_DIRS}
OWN_DIRS_PERMS+=	${dir}	${INN_USER} ${INN_GROUP} 0775
.endfor
.for dir in ${INN_DATADIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/${dir}	${INN_USER} ${INN_GROUP} 0775
.endfor
.for dir in ${INN_SPOOLDIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/spool/${dir} \
						${INN_USER} ${INN_GROUP} 0775
.endfor

CFILES=			actsync.cfg actsync.ign buffindexed.conf \
			control.ctl control.ctl.local cycbuff.conf \
			distrib.pats distributions \
			expire.ctl incoming.conf inn.conf innfeed.conf \
			innreport.conf innwatch.ctl \
			innshellvars.local innshellvars.pl.local \
			innshellvars.tcl.local \
			localgroups moderators \
			motd.innd motd.nnrpd \
			news2mail.cf newsfeeds nnrpd.track \
			nntpsend.ctl nocem.ctl ovdb.conf passwd.nntp \
			inn-radius.conf readers.conf send-uucp.cf \
			storage.conf subscriptions
.for file in ${CFILES}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${file} ${PKG_SYSCONFDIR}/${file} \
			${INN_USER} ${INN_GROUP} 0664
.endfor

CONF_FILES_PERMS+=	${EXAMPLEDIR}/active.minimal ${INN_DATA_DIR}/db/active ${INN_USER} ${INN_GROUP} 0664
CONF_FILES_PERMS+=	${EXAMPLEDIR}/newsgroups.minimal ${INN_DATA_DIR}/db/newsgroups ${INN_USER} ${INN_GROUP} 0664

DBFILES=		active.times history

HTTPFILES=		innreport.css

CONF_FILES_PERMS+=	${EXAMPLEDIR}/innreport.css ${INN_DATA_DIR}/http/innreport.css ${INN_USER} ${INN_GROUP} 0664

.for file in ${DBFILES}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${file} ${INN_DATA_DIR}/db/${file} \
			${INN_USER} ${INN_GROUP} 0664
.endfor

FILTERFILES=		INN.py filter_innd.py nnrpd.py nnrpd_access.py \
			nnrpd_auth.py nnrpd_dynamic.py \
			filter_innd.pl filter_nnrpd.pl nnrpd_access.pl \
			nnrpd_auth.pl startup_innd.pl

.for file in ${FILTERFILES}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/filter/${file} ${INN_PATHBIN}/filter/${file} \
			${INN_USER} ${INN_GROUP} 0664
.endfor

RCD_SCRIPTS=		innd

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-sendmail=/usr/lib/sendmail
.else
CONFIGURE_ARGS+=	--with-sendmail=/usr/sbin/sendmail
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

.include "options.mk"

TEST_TARGET=    tests

pre-install:
.for file in ${CFILES} active.minimal newsgroups.minimal
	${INSTALL_DATA} ${WRKSRC}/site/${file} ${DESTDIR}${EXAMPLEDIR}
.endfor
.for file in ${DBFILES} ${HTTPFILES}
	${TOUCH} ${WRKSRC}/site/${file}
	${INSTALL_DATA} ${WRKSRC}/site/${file} ${DESTDIR}${EXAMPLEDIR}
.endfor
.for file in ${FILTERFILES}
	${INSTALL_DATA} ${WRKSRC}/site/${file} ${DESTDIR}${EXAMPLEDIR}/filter
.endfor

post-install:
.for file in cnfsstat ctlinnd makehistory innbind
	${RM} -f ${DESTDIR}${PREFIX}/sbin/${file}
	${LN} -s ${DESTDIR}${PREFIX}/${INN_PATHBIN}/${file}	\
				${DESTDIR}${PREFIX}/sbin
.endfor
	${RM} -f ${DESTDIR}${PREFIX}/bin/inews
	${LN} -s ${DESTDIR}${PREFIX}/${INN_PATHBIN}/inews	\
			${DESTDIR}${PREFIX}/bin
	${RM} -f ${DESTDIR}${PREFIX}/bin/rnews
	${LN} -s ${DESTDIR}${PREFIX}/${INN_PATHBIN}/rnews	\
			${DESTDIR}${PREFIX}/bin
.for file in libinn.a libstorage.a libinnhist.a
	${CHMOD} 644 ${DESTDIR}${PREFIX}/lib/${file}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
