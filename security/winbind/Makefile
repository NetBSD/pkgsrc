# $NetBSD: Makefile,v 1.1.1.1 2002/07/29 04:19:00 jlam Exp $

DISTNAME=		samba-2.2.5
PKGNAME=		winbind-2.2.5
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/ \
			ftp://ring.asahi-net.or.jp/pub/net/samba/ \
			ftp://samba.anu.edu.au/pub/samba/ \
			http://de.samba.org/samba/ftp/ \
			ftp://ftp.sunet.se/pub/unix/utilities/samba/
COUNTRY_MIRRORS=	au1 ca fi fr de it pl ru sg se us1 us6
.for COUNTRY in ${COUNTRY_MIRRORS}
MASTER_SITES+=		ftp://${COUNTRY}.samba.org/pub/samba/
.endfor
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		unified logon information between UNIX and Windows NT

DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba

USE_BUILDLINK_ONLY=	# defined
WRKSRC=			${WRKDIR}/${DISTNAME}/source

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PKG_SYSCONFSUBDIR?=	samba

VARDIR?=		/var
SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}
SAMBA_DATADIR=		${PREFIX}/share
SAMBA_LOCKDIR?=		${VARDIR}/db/samba
SAMBA_LOGDIR?=		${VARDIR}/log
SAMBA_PIDDIR?=		${VARDIR}/run
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--localstatedir=${VARDIR}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
CONFIGURE_ARGS+=	--with-codepagedir=${SAMBA_DATADIR}/samba/codepages
CONFIGURE_ARGS+=	--with-datadir=${SAMBA_DATADIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--with-swatdir=${SAMBA_DATADIR}/samba/swat

CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${BUILDLINK_DIR}
CFLAGS+=		-I${BUILDLINK_DIR}/include/openssl	# ssl.h, err.h

CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no

CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-winbind

FILES_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR}

ALL_TARGET=		nsswitch

PAMDIR=			${PREFIX}/lib/security
RCD_SCRIPTS=		winbindd

INSTALL_LIBRARY= \
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

# The man pages remain with the samba package.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wbinfo ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/winbindd ${PREFIX}/sbin
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/pam_winbind.so ${PAMDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/libnss_winbind.so ${PREFIX}/lib

post-install:
	@for file in ${RCD_SCRIPTS}; do					\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${file}.sh	\
			> ${WRKDIR}/$${file}.sh;			\
		${INSTALL_SCRIPT} ${WRKDIR}/$${file}.sh			\
			${PREFIX}/etc/rc.d/$${file};			\
	done

.include "../../security/PAM/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
