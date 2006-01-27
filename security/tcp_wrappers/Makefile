# $NetBSD: Makefile,v 1.28 2006/01/27 17:33:55 joerg Exp $

DISTNAME= 	tcp_wrappers_7.6-ipv6.1
PKGNAME=	tcp_wrappers-7.6.1
PKGREVISION= 	4
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html
COMMENT=	Monitor and filter incoming requests for network services

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes

BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

BUILD_TARGET.${OPSYS}?=	generic		# good luck!
BUILD_TARGET.Darwin=	netbsd
BUILD_TARGET.Interix=	netbsd
BUILD_TARGET.Linux=	${LOWER_OPSYS}
.if !empty(OPSYS:M*BSD)
BUILD_TARGET.${OPSYS}=	netbsd
.endif
BUILD_TARGET.SunOS=	sunos5
BUILD_TARGET.IRIX=	${LOWER_OPSYS:C|\..*||}
BUILD_TARGET=		${BUILD_TARGET.${OPSYS}}

.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
.  if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
MAKE_ENV+=	IPV6="-DHAVE_IPV6 -DUSE_GETHOSTBYNAME2"
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

INSTALLATION_DIRS=	bin include lib libexec ${PKGMANDIR}/man3 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

post-build:
	cd ${WRKSRC}; for file in *.[0-9]; do				\
		${MV} -f $$file $$file.BAK;				\
		${SED}	-e "s|/etc/hosts\.|${PKG_SYSCONFDIR}/hosts.|g"	\
			$$file.BAK > $$file;				\
	done

do-install:
	cd ${WRKSRC}; ${LIBTOOL} --mode=install \
		${INSTALL_LIB} libwrap.la ${PREFIX}/lib
	cd ${WRKSRC}; ${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} \
		tcpdmatch try-from safe_finger tcpdchk ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} tcpd.h ${PREFIX}/include
	cd ${WRKSRC}; ${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} tcpd ${PREFIX}/libexec
	cd ${WRKSRC}; ${INSTALL_DATA} *.3 ${PREFIX}/${PKGMANDIR}/man3
	cd ${WRKSRC}; ${INSTALL_DATA} *.5 ${PREFIX}/${PKGMANDIR}/man5
	cd ${WRKSRC}; ${INSTALL_DATA} *.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcp_wrappers
	cd ${WRKSRC}; ${INSTALL_DATA} README README.NIS README.ipv6 \
		${PREFIX}/share/doc/tcp_wrappers

.include "../../mk/bsd.pkg.mk"
