# $NetBSD: Makefile,v 1.87 2008/01/18 05:08:52 tnn Exp $

DISTNAME=		inn-2.4.3
PKGREVISION=		2
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.isc.org/sw/inn/
COMMENT=		The public release of InterNet News (INN)

CONFLICTS+=		libradius-[0-9]* nntpclnt-[0-9]*

.include "Makefile.common"

BUILD_DEFS+=		INN_DATA_DIR
FILES_SUBST+=		INN_DATA_DIR=${INN_DATA_DIR:Q}

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${INN_PREFIX}
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-setgid-inews 				\
			--enable-uucp-rnews 				\
			--with-perl					\
			--with-openssl=${SSLBASE:Q}			\
			--with-tmp-dir=${INN_DATA_DIR}/tmp		\
			--with-db-dir=${INN_DATA_DIR}/db 		\
			--with-etc-dir=${INN_DATA_DIR}/etc 		\
			--with-log-dir=${INN_DATA_DIR}/log 		\
			--with-run-dir=${INN_DATA_DIR}/run 		\
			--with-spool-dir=${INN_SPOOL:Q}			\
			--with-news-user=${INN_USER:Q}			\
			--with-news-group=${INN_GROUP:Q}
CONFIGURE_ENV+=		_PATH_PERL=${PERL5:Q}
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

PKG_SYSCONFDIR.inn=	${INN_DATA_DIR}/etc
EXAMPLEDIR=		${PREFIX}/share/examples/inn
INN_DATADIRS=		db etc log log/OLD run spool tmp
INN_SPOOLDIRS=		archive articles overview incoming incoming/bad	\
			outgoing uniover innfeed

OWN_DIRS=		${PREFIX}/etc/nntp
OWN_DIRS_PERMS=		${INN_DATA_DIR}			${INN_USER} ${INN_GROUP} 0775
.for dir in ${INN_DATADIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/${dir}		${INN_USER} ${INN_GROUP} 0775
.endfor
.for dir in ${INN_SPOOLDIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/spool/${dir}	${INN_USER} ${INN_GROUP} 0775
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

post-patch:
	${RM} -f ${WRKSRC}/samples/inn.conf.in.orig_dist

post-build:
	for DIR in backends expire frontends innd innfeed lib nnrpd	\
		storage; do \
		${SED} -e 's#-b .OLD##' -e 's#-G#-g#' -e 's#-O#-o#'	\
			${WRKSRC}/$$DIR/Makefile			\
			> ${WRKSRC}/$$DIR/Makefile.patch;		\
		${MV} ${WRKSRC}/$$DIR/Makefile.patch			\
			${WRKSRC}/$$DIR/Makefile;			\
	done

pre-install:
	for DIR in ${INN_DATA_DIR} ${PREFIX}/etc/nntp ${PREFIX}/inn; do	\
		${INSTALL_DATA_DIR} $$DIR;				\
	done

post-install:
	${RM} -f ${PREFIX}/bin/inews
	${LN} -s ../inn/bin/inews ${PREFIX}/bin/inews
	${INSTALL_DATA_DIR} ${PREFIX}/include/inn
	cd ${PREFIX}/include/inn;					\
	for FILE in config.h dbz.h libinn.h storage.h; do		\
	  ${LN} -s ${INN_PREFIX}/include/$$FILE $$FILE;			\
	done
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	for FILE in `ls -1 ${WRKSRC}/samples/* |			\
		     ${EGREP} -v '(Makefile|.*\.(in|orig)$$)'`; do	\
		${INSTALL_DATA} $$FILE ${EXAMPLEDIR};			\
	done

.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
