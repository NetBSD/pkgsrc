# $NetBSD: Makefile,v 1.104 2020/06/21 15:10:47 taca Exp $
#

DISTNAME=	ntp-4.2.8p14
CATEGORIES=	net time
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-4.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ntp.org/
COMMENT=	Network Time Protocol Version 4

CONFLICTS+=	openntpd-[0-9]*

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pax perl:run

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-locfile=loc/pkgsrc
CONFIGURE_ENV+=		PATH_PERL=${PERL5}

OVERRIDE_DIRDEPTH=	4

DOCS+=		COPYRIGHT ChangeLog NEWS README* TODO
DOCDIR=		share/doc/ntp
EXAMPLESDIR=	share/examples/ntp4
ALL_NTP_DOCS=	${DESTDIR}${PREFIX}/${DOCDIR} ${DESTDIR}${PREFIX}/${EXAMPLESDIR}

INSTALLATION_DIRS=	${DOCDIR} ${EXAMPLESDIR}

RCD_SCRIPTS=	ntpd ntpdate

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/conf && pax -rw -pm . ${DESTDIR}${PREFIX}/${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ALL_NTP_DOCS}
	${FIND} ${ALL_NTP_DOCS} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${ALL_NTP_DOCS} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PLIST_VARS+=	ntptime tickadj timetrim

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PLIST.ntptime=		yes
PLIST.tickadj=		yes
.elif ${OPSYS} == "IRIX"
PLIST.timetrim=		yes
.elif ${OPSYS} == "Darwin"
PLIST.tickadj=		yes
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
