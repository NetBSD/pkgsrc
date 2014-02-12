# $NetBSD: Makefile,v 1.76 2014/02/12 23:18:24 tron Exp $
#

DISTNAME=	ntp-dev-4.2.7p410
PKGREVISION=	1
CATEGORIES=	net time
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ntp.org/
COMMENT=	Network Time Protocol Version 4

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	openntpd-[0-9]*

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pax perl:run

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=--with-locfile=loc/pkgsrc
CONFIGURE_ENV+=	  PATH_PERL=${PERL5}

DOCDIR=		${DESTDIR}${PREFIX}/share/doc/ntp4
EXAMPLESDIR=	${DESTDIR}${PREFIX}/share/examples/ntp4
ALL_NTP_DOCS=	${DOCDIR} ${EXAMPLESDIR}

RCD_SCRIPTS=	ntpd ntpdate

post-install:
	${MKDIR} ${DOCDIR}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/html && pax -rw -pm . ${DOCDIR}
	cd ${WRKSRC}/conf && pax -rw -pm . ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ALL_NTP_DOCS}
	${FIND} ${ALL_NTP_DOCS} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${ALL_NTP_DOCS} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PLIST_VARS+=	ntptime tickadj timetrim

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PLIST.ntptime=		yes
PLIST.tickadj=		yes
.elif ${OPSYS} == "IRIX"
PLIST.timetrim=		yes
.endif

# chroot jail support
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-clockctl
.elif ${OPSYS} == "Linux" && exists(/usr/include/sys/capability.h)
CONFIGURE_ARGS+=	--enable-linuxcaps
.else
# no chroot/privilege drop supported
.endif

CPPFLAGS.Linux+=	-D_GNU_SOURCE	# for struct in6_pktinfo

.include "../../security/openssl/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openssl-incdir=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-libdir=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-crypto=openssl

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
