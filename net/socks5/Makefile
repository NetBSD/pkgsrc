# $NetBSD: Makefile,v 1.48 2009/06/30 00:07:21 joerg Exp $

DISTNAME=	socks5-v1_0r2
PKGNAME=	socks5-1.0.2
PKGREVISION=	6
CATEGORIES=	net security
MASTER_SITES=	# empty -- manual fetch needed
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	ambrisko@ambrisko.roble.com
HOMEPAGE=	http://www.socks.permeo.com/
COMMENT=	SOCKS v5 application layer gateway and clients
# XXX missing
LICENSE=		socks5-license

RESTRICTED=		no commercial use
# Set all pending someone looking at the license.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

CONFLICTS=	socks4-[0-9]*

# here are some extra configure args you may wish to use
# see the readme file before screwing with them
#
#EXTRA_CONFIGURE_ARGS+= \
#			--with-default-server=socks.mydomain.com \
#			--with-syslog-facility=LOG_AUTH \
#			--with-passwd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/socks5-v1.0r2
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
			--with-srvconffile=${PREFIX}/etc/socks5.conf \
			--with-srvpidfile=/var/run/socks5.pid \
			--with-srvidtfile=/var/run/socks5.ident \
			${EXTRA_CONFIGURE_ARGS}
LIBS+=			-lcrypt
RCD_SCRIPTS=		socks5

EXAMPLE_FILES=	README multiple_server.example server_2_multiple_server.example
EXAMPLE_FILES+=	single_homed_host.example socks5.conf.dualhomed
EXAMPLE_FILES+=	socks5.conf.gssapi socks5.conf.multipleservers
EXAMPLE_FILES+=	socks5.conf.server2server socks5.conf.singlehomed
EXAMPLE_DIR=	${PREFIX}/share/examples/socks5

INSTALLATION_DIRS=	bin include ${EXAMPLE_DIR} ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5
INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			SHLIB_DIR=${DESTDIR}${PREFIX}/lib \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			prefix=${DESTDIR}${PREFIX} \
			exec_prefix=${DESTDIR}${PREFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && chmod 555 rarchie rfinger rftp rping rtelnet rtraceroute runsocks rwhois
	${MV} ${DESTDIR}${PREFIX}/lib/libsocks5_sh.so ${DESTDIR}${PREFIX}/lib/libsocks5_sh.so.0.0
	${LN} -sf libsocks5_sh.so.0.0 ${DESTDIR}${PREFIX}/lib/libsocks5_sh.so.0
	${LN} -sf libsocks5_sh.so.0.0 ${DESTDIR}${PREFIX}/lib/libsocks5_sh.so
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}${EXAMPLE_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
