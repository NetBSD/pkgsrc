# $NetBSD: Makefile,v 1.37 2004/10/03 00:17:56 tv Exp $
#

DISTNAME=	ntp-4.2.0
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/		\
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.ntp.org/
COMMENT=	Network Time Protocol Version 4

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	openntpd-[0-9]*

GNU_CONFIGURE=	YES
USE_PERL5=	build
USE_BUILDLINK3= YES
USE_PKGINSTALL=	YES

CONFIGURE_ENV+=	PATH_PERL="${PERL5}" ac_cv_header_sys_soundcard_h=no

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

DOCDIR=		${PREFIX}/share/doc/html
EXAMPLESDIR=	${PREFIX}/share/examples
ALL_NTP_DOCS=	${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4

RCD_SCRIPTS=	ntpd ntpdate

post-install:
	(cd ${WRKSRC} &&						\
	    ${PAX} -rw -pe -s "/html/ntp4/" html ${DOCDIR};		\
	    ${PAX} -rw -pe -s "/conf/ntp4/" conf ${EXAMPLESDIR});	\
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ALL_NTP_DOCS};		\
	${FIND} ${ALL_NTP_DOCS} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}; \
	${FIND} ${ALL_NTP_DOCS} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE};

.include "../../mk/bsd.prefs.mk"

TIMETRIM=	""
NO_TIMETRIM=	"@comment "

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
.elif ${OPSYS} == "IRIX"
TIMETRIM=	"@comment "
NO_TIMETRIM=	""
.endif

PLIST_SUBST+=	TIMETRIM=${TIMETRIM} NO_TIMETRIM=${NO_TIMETRIM}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/buildlink3/bsd.builtin.mk"

.if !empty(USE_BUILTIN.openssl:M[nN][oO])
CONFIGURE_ARGS+=	--with-openssl-incdir=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-libdir=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-crypto=openssl
.endif

.include "../../mk/bsd.pkg.mk"
