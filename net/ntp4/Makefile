# $NetBSD: Makefile,v 1.55 2008/05/26 02:13:22 joerg Exp $
#

DISTNAME=	ntp-4.2.0
PKGREVISION=	11
CATEGORIES=	net time
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/		\
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ntp.org/
COMMENT=	Network Time Protocol Version 4

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	openntpd-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	pax perl

CONFIGURE_ENV+=	PATH_PERL=${PERL5:Q} ac_cv_header_sys_soundcard_h=no

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

DOCDIR=		${PREFIX}/share/doc/ntp4
EXAMPLESDIR=	${PREFIX}/share/examples/ntp4
ALL_NTP_DOCS=	${DOCDIR} ${EXAMPLESDIR}

RCD_SCRIPTS=	ntpd ntpdate

post-install:
	cd ${WRKSRC}/html && pax -rw . ${DOCDIR}
	cd ${WRKSRC}/conf && pax -rw . ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ALL_NTP_DOCS}
	${FIND} ${ALL_NTP_DOCS} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${ALL_NTP_DOCS} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	ntptime timetrim

.if ${OPSYS} == "NetBSD"
#
# Use POSIX nanosecond timers when available, but not otherwise.
#
LOWER_OPSYS_VERSUFFIX=	1
MACHINE_GNU_PLATFORM=	${LOWER_ARCH}--${LOWER_OPSYS}${LOWER_OPSYS_VERSUFFIX}
. for __wildcard__ in 1.6[N-Z]* 2*
.  if ${OS_VERSION:M${__wildcard__}} != ""
LOWER_OPSYS_VERSUFFIX=	2
.  endif
. endfor
#
# Don't pick up libwww's -lmd5, until buildlink can be fixed.
#
CONFIGURE_ENV+=	ac_cv_lib_md5_MD5Init=no
PLIST.ntptime=		yes
.elif ${OPSYS} == "IRIX"
PLIST.timetrim=		yes
.endif

.include "../../security/openssl/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openssl-incdir=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-libdir=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-crypto=openssl

.include "../../mk/bsd.pkg.mk"
