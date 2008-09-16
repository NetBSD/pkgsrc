# $NetBSD: Makefile,v 1.92 2008/09/16 23:06:19 spz Exp $

DISTNAME=		inn-2.4.5
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/

MAINTAINER=		spz@NetBSD.org
HOMEPAGE=		http://www.isc.org/sw/inn/
COMMENT=		The public release of InterNet News (INN)

CONFLICTS+=		libradius-[0-9]* nntpclnt-[0-9]*

.include "Makefile.common"

BUILD_DEFS+=		INN_DATA_DIR
FILES_SUBST+=		INN_DATA_DIR=${INN_DATA_DIR:Q}

BUILD_DEFS+=		INN_PATHBIN
FILES_SUBST+=		INN_PATHBIN=${PREFIX}/${INN_PATHBIN:Q}

MESSAGE_SUBST+=		INN_PATHBIN=${INN_PATHBIN:Q}

PLIST_SUBST+=		INN_PATHBIN=${INN_PATHBIN:Q}

SUBST_CLASSES+=		BADPATHBIN
SUBST_STAGE.BADPATHBIN=	post-patch
SUBST_MESSAGE.BADPATHBIN=	"fixing up unfortunate pathbin paths"
SUBST_FILES.BADPATHBIN= Makefile.global.in \
			samples/inn.conf.in samples/newsfeeds.in \
			scripts/innshellvars.in scripts/innshellvars.pl.in \
			scripts/innshellvars.tcl.in backends/news2mail.in \
			control/controlbatch.in control/controlchan.in
SUBST_SED.BADPATHBIN=	-e 's,@prefix@/bin,${PREFIX}/${INN_PATHBIN:Q},g' \
			-e 's,$$(PATHNEWS)/bin,${PREFIX}/${INN_PATHBIN:Q},g'


GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${INN_PREFIX}
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-setgid-inews 				\
			--enable-largefiles				\
			--with-openssl=${SSLBASE:Q}			\
			--with-etc-dir=${PREFIX}/etc/inn 		\
			--with-doc-dir=${PREFIX}/share/doc/inn	 	\
			--with-control-dir=${PREFIX}/${INN_PATHBIN}/control \
			--with-filter-dir=${PREFIX}/${INN_PATHBIN}/filter \
			--with-tmp-dir=${INN_DATA_DIR}/tmp		\
			--with-db-dir=${INN_DATA_DIR}/db 		\
			--with-log-dir=${INN_DATA_DIR}/log 		\
			--with-run-dir=${INN_DATA_DIR}/run 		\
			--includedir=${PREFIX}/include/inn 		\
			--with-spool-dir=${INN_SPOOL:Q}			\
			--with-news-user=${INN_USER:Q}			\
			--with-news-group=${INN_GROUP:Q}
CONFIGURE_ENV+=		_PATH_AWK=${TOOLS_AWK:Q}
CONFIGURE_ENV+=		_PATH_EGREP=${TOOLS_EGREP:Q}
CONFIGURE_ENV+=		_PATH_SED=${TOOLS_SED:Q}
CONFIGURE_ENV+=		_PATH_SH=${TOOLS_SH:Q}
CONFIGURE_ENV+=		_PATH_SORT=${TOOLS_SORT:Q}
CONFIGURE_ENV+=		GZIP=${TOOLS_GZIP_CMD:Q}
USE_TOOLS+=		awk egrep gzip perl:run sed sh sort yacc

PKG_GROUPS_VARS+=	INN_GROUP
PKG_USERS_VARS+=	INN_USER

PKG_GROUPS=		${INN_GROUP}
PKG_USERS=		${INN_USER}:${INN_GROUP}
PKG_GECOS.${INN_USER}=	Internet\ News
PKG_HOME.${INN_USER}=	${INN_DATA_DIR}
PKG_SHELL.${INN_USER}=	${SH}

PKG_SYSCONFDIR.inn=	${PREFIX}/etc/inn
EXAMPLEDIR=		${PREFIX}/share/examples/inn
INN_DATADIRS=		log log/OLD run tmp db spool
INN_SPOOLDIRS=		archive articles overview incoming incoming/bad	\
			outgoing uniover innfeed

MAKE_DIRS+=		${PREFIX}/bin
MAKE_DIRS+=		${PREFIX}/sbin
MAKE_DIRS+=		${PREFIX}/lib

INN_DIRS+=		${PREFIX}/etc/nntp
INN_DIRS+=		${PREFIX}/etc/inn
INN_DIRS+=		${INN_DATA_DIR}

OWN_DIRS+=		${PREFIX}/${INN_PATHBIN}
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
			control.ctl cycbuff.conf distrib.pats \
			expire.ctl incoming.conf inn.conf innfeed.conf \
			innreport.conf innwatch.ctl moderators \
			motd.news news2mail.cf newsfeeds nnrpd.track \
			nntpsend.ctl ovdb.conf overview.fmt passwd.nntp \
			radius.conf readers.conf sasl.conf storage.conf
.for file in ${CFILES}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${file} ${PKG_SYSCONFDIR}/${file} \
			${INN_USER} ${INN_GROUP} 0664
.endfor

RCD_SCRIPTS=		innd

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

pre-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	for FILE in `ls -1 ${WRKSRC}/samples/* |			\
		     ${EGREP} -v '(Makefile|.*\.(in|orig)$$)'`; do	\
		${INSTALL_DATA} $$FILE ${EXAMPLEDIR};			\
	done
	# makedbz needs these earlier than pkgsrc will install them normally
	if [ ! -f ${PKG_SYSCONFDIR}/inn.conf ] ; then			\
		${INSTALL} ${COPY} -o ${INN_USER} -g ${INN_GROUP} -m 0664 \
				${EXAMPLEDIR}/inn.conf			\
				${PKG_SYSCONFDIR}/inn.conf ;		\
	fi
	if [ ! -d ${INN_DATA_DIR}/db ] ; then				\
		${INSTALL} -d -o ${INN_USER} ${INN_DATA_DIR}/db ;	\
	fi
	

post-install:
	for FILE in cnfsstat ctlinnd inndstart makehistory ; do		\
		${INSTALL} -l rs ${PREFIX}/${INN_PATHBIN}/$$FILE     \
				${PREFIX}/sbin/$$FILE ;                 \
	done
	${INSTALL} -l rs ${PREFIX}/${INN_PATHBIN}/inews ${PREFIX}/bin/inews
	${INSTALL} -l rs ${PREFIX}/${INN_PATHBIN}/rnews ${PREFIX}/bin/rnews
	for FILE in libinn.a libstorage.a libinnhist.a ; do		\
		${CHMOD} 644 ${PREFIX}/lib/$$FILE ;			\
	done
	if [ -d ${INN_DATA_DIR}/etc ] ; then				\
		echo "" ; 						\
		echo "WARNING WARNING WARNING WARNING WARNING WARNING WARNING";\
		echo "" ; 						\
		echo "WARNING: old inn config directory ${INN_DATA_DIR}/etc found";\
		echo "WARNING: please move your config to ${PREFIX}/etc/inn"; \
		echo "WARNING: before starting your new inn install" ;	\
		echo "" ; 						\
		echo "WARNING WARNING WARNING WARNING WARNING WARNING WARNING";\
		echo "" ; 						\
	fi

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
