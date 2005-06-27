# $NetBSD: Makefile,v 1.64 2005/06/27 19:11:25 tron Exp $

DISTNAME=		inn-2.4.1
PKGREVISION=		5
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/ \
			ftp://ftp.sunet.se/pub/news/nntp/inn/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.isc.org/inn.html
COMMENT=		The public release of InterNet News (INN)

CONFLICTS+=		nntpclnt-[0-9]*

.include "Makefile.common"
BUILD_DEFS+=		USE_INET6
BUILD_DEFS+=		INN_DATA_DIR INN_USER INN_GROUP
FILES_SUBST+=		INN_DATA_DIR=${INN_DATA_DIR}

USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${INN_PREFIX}
CONFIGURE_ARGS+=	--enable-setgid-inews 				\
			--enable-uucp-rnews 				\
			--mandir=${PREFIX}/man 				\
			--with-perl					\
			--with-openssl=${SSLBASE}			\
			--with-tmp-dir=${INN_DATA_DIR}/tmp		\
			--with-db-dir=${INN_DATA_DIR}/db 		\
			--with-etc-dir=${INN_DATA_DIR}/etc 		\
			--with-log-dir=${INN_DATA_DIR}/log 		\
			--with-run-dir=${INN_DATA_DIR}/run 		\
			--with-spool-dir=${INN_SPOOL}			\
			--with-news-user=${INN_USER}			\
			--with-news-group=${INN_GROUP}
CONFIGURE_ENV+=		_PATH_PERL=${PERL5}
CONFIGURE_ENV+=		_PATH_AWK="${TOOLS_AWK}"
CONFIGURE_ENV+=		_PATH_EGREP="${TOOLS_EGREP}"
CONFIGURE_ENV+=		_PATH_SED="${TOOLS_SED}"
CONFIGURE_ENV+=		_PATH_SH="${TOOLS_SH}"
CONFIGURE_ENV+=		_PATH_SORT="${TOOLS_SORT}"
CONFIGURE_ENV+=		GZIP="${TOOLS_GZIP_CMD:C/ .*//W}"
USE_TOOLS+=		awk egrep gzip sed sh sort yacc

PKG_USERS=		${INN_USER}:${INN_GROUP}::Internet\\ News:${INN_DATA_DIR}:${SH}
PKG_GROUPS=		${INN_GROUP}

PKG_SYSCONFDIR.inn=	${INN_DATA_DIR}/etc
EXAMPLEDIR=		${PREFIX}/share/examples/inn
INN_DATADIRS=		db etc log log/OLD run spool tmp
INN_SPOOLDIRS=		archive articles overview incoming incoming/bad	\
			outgoing uniover innfeed

OWN_DIRS=		${PREFIX}/etc/nntp
OWN_DIRS_PERMS=		${INN_DATA_DIR}			${INN_USER} ${INN_GROUP} 0775
.for DIR in ${INN_DATADIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/${DIR}		${INN_USER} ${INN_GROUP} 0775
.endfor
.for DIR in ${INN_SPOOLDIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/spool/${DIR}	${INN_USER} ${INN_GROUP} 0775
.endfor

CFILES=			actsync.cfg actsync.ign buffindexed.conf \
			control.ctl cycbuff.conf distrib.pats \
			expire.ctl incoming.conf inn.conf innfeed.conf \
			innreport.conf innwatch.ctl moderators \
			motd.news news2mail.cf newsfeeds nnrpd.track \
			nntpsend.ctl ovdb.conf overview.fmt passwd.nntp \
			radius.conf readers.conf sasl.conf storage.conf
.for FILE in ${CFILES}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE} \
			${INN_USER} ${INN_GROUP} 0664
.endfor

RCD_SCRIPTS=		innd

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-sendmail=/usr/lib/sendmail
.else
CONFIGURE_ARGS+=	--with-sendmail=/usr/sbin/sendmail
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

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
