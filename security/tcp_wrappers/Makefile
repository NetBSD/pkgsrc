# $NetBSD: Makefile,v 1.17 2004/04/26 01:14:04 tv Exp $

DISTNAME= 	tcp_wrappers_7.6-ipv6.1
PKGNAME=	tcp_wrappers-7.6.1
PKGREVISION= 	1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html
COMMENT=	Monitor and filter incoming requests for network services

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

ALL_TARGET.${OPSYS}?=	generic		# good luck!
ALL_TARGET.Darwin=	netbsd
ALL_TARGET.Interix=	netbsd
ALL_TARGET.Linux=	${LOWER_OPSYS}
.if !empty(OPSYS:M*BSD)
ALL_TARGET.${OPSYS}=	netbsd
.endif
ALL_TARGET.SunOS=	sunos5
ALL_TARGET.IRIX=	${LOWER_OPSYS:C|\..*||}
ALL_TARGET=		${ALL_TARGET.${OPSYS}}

.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
.  if !empty(OPSYS:M*BSD)
MAKE_ENV+=	IPV6="-DHAVE_IPV6 -DUSE_GETHOSTBYNAME2"
MAKE_ENV+=	UCHAR="-Duchar_t=\"unsigned char\""
.  elif ${OPSYS} != "Linux"
MAKE_ENV+=	IPV6=-DHAVE_IPV6
.  endif
.endif

# Default to /etc/hosts.{allow,deny} for the configuration files to match
# the historic location of these files.  This may be changed by setting
# PKG_SYSCONFDIR.tcp_wrappers to a different value in /etc/mk.conf.
#
PKG_SYSCONFDIR.tcp_wrappers?=	/etc
MAKE_ENV+=	PKGSYSCONFDIR=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	bin include lib libexec man/man3 man/man5 man/man8

post-build:
	cd ${WRKSRC}; for file in *.[0-9]; do				\
		${MV} -f $$file $$file.BAK;				\
		${SED}	-e "s|/etc/hosts\.|${PKG_SYSCONFDIR}/hosts.|g"	\
			$$file.BAK > $$file;				\
	done

do-install:
	cd ${WRKSRC}; ${LIBTOOL} ${INSTALL_DATA} libwrap.la ${PREFIX}/lib
	cd ${WRKSRC}; ${LIBTOOL} ${INSTALL_PROGRAM} \
		tcpdmatch try-from safe_finger tcpdchk ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} tcpd.h ${PREFIX}/include
	cd ${WRKSRC}; ${LIBTOOL} ${INSTALL_PROGRAM} tcpd ${PREFIX}/libexec
	cd ${WRKSRC}; ${INSTALL_DATA} *.3 ${PREFIX}/man/man3
	cd ${WRKSRC}; ${INSTALL_DATA} *.5 ${PREFIX}/man/man5
	cd ${WRKSRC}; ${INSTALL_DATA} *.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcp_wrappers
	cd ${WRKSRC}; ${INSTALL_DATA} README README.NIS README.ipv6 \
		${PREFIX}/share/doc/tcp_wrappers

.include "../../mk/bsd.pkg.mk"
