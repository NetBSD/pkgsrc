# $NetBSD: Makefile,v 1.37 2002/09/29 10:39:36 jlam Exp $

DISTNAME=		inn-2.3.3
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/ \
			ftp://ftp.sunet.se/pub/news/nntp/inn/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.isc.org/inn.html
COMMENT=		the public release of InterNet News (INN)

CONFLICTS+=		nntpclnt-[0-9]*

PATCH_SITES=		ftp://ftp.north.ad.jp/pub/IPv6/INN/
PATCHFILES=		inn-2.3.3-v6-20020618.diff.gz
PATCH_DIST_STRIP=	-p1

INN_DATA_DIR?=		/var/news
BUILD_DEFS+=		INN_DATA_DIR
FILES_SUBST+=		INN_DATA_DIR=${INN_DATA_DIR}

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/inn
CONFIGURE_ARGS+=	--enable-setgid-inews \
			--enable-uucp-rnews \
			--mandir=${PREFIX}/man \
			--with-perl --with-tmp-path=${INN_DATA_DIR}/tmp \
			--with-db-dir=${INN_DATA_DIR}/db \
			--with-etc-dir=${INN_DATA_DIR}/etc \
			--with-log-dir=${INN_DATA_DIR}/log \
			--with-run-dir=${INN_DATA_DIR}/run \
			--with-spool-dir=${INN_DATA_DIR}/spool
CONFIGURE_ENV+=		_PATH_PERL=${PERL5}

PKG_USERS=		news:news::Internet\\ News:${INN_DATA_DIR}:${SH}
PKG_GROUPS=		news

PKG_SYSCONFDIR.inn=	${INN_DATA_DIR}/etc
EXAMPLEDIR=		${PREFIX}/share/examples/inn
INN_DATADIRS=		db etc log log/OLD run spool tmp
INN_SPOOLDIRS=		articles overview incoming incoming/bad	\
			outgoing uniover innfeed

OWN_DIRS=		${PREFIX}/etc/nntp
OWN_DIRS_PERMS=		${INN_DATA_DIR}			news news 0775
.for DIR in ${INN_DATADIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/${DIR}		news news 0775
.endfor
.for DIR in ${INN_SPOOLDIRS}
MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/spool/${DIR}	news news 0775
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
			news news 0664
.endfor

RCD_SCRIPTS=		innd

.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-sendmail=/usr/lib/sendmail
.else
CONFIGURE_ARGS+=	--with-sendmail=/usr/sbin/sendmail
.endif

.if (${MACHINE_ARCH} == arm32)
.  include "../../lang/gcc/buildlink2.mk"
.endif

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
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	for FILE in `ls -1 ${WRKSRC}/samples/* |			\
		     ${EGREP} -v '(Makefile|.*\.(in|orig)$$)'`; do	\
		${INSTALL_DATA} $$FILE ${EXAMPLEDIR};			\
	done

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
