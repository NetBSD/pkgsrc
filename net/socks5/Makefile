# $NetBSD: Makefile,v 1.40 2005/12/05 20:50:49 rillig Exp $

DISTNAME=	socks5-v1_0r2
PKGNAME=	socks5-1.0.2
PKGREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	# empty -- manual fetch needed
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	ambrisko@ambrisko.roble.com
HOMEPAGE=	http://www.socks.permeo.com/
COMMENT=	SOCKS v5 application layer gateway and clients

CONFLICTS=	socks4-[0-9]*

RESTRICTED=		"no commercial use"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# here are some extra configure args you may wish to use
# see the readme file before screwing with them
#
#EXTRA_CONFIGURE_ARGS+= \
#			--with-default-server=socks.mydomain.com \
#			--with-syslog-facility=LOG_AUTH \
#			--with-passwd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/socks5-v1.0r2
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
			--with-srvconffile=${PREFIX}/etc/socks5.conf \
			--with-srvpidfile=/var/run/socks5.pid \
			--with-srvidtfile=/var/run/socks5.ident \
			${EXTRA_CONFIGURE_ARGS}
LIBS+=			-lcrypt
INSTALLATION_DIRS=	include
RCD_SCRIPTS=		socks5

EXAMPLE_FILES=	README multiple_server.example server_2_multiple_server.example
EXAMPLE_FILES+=	single_homed_host.example socks5.conf.dualhomed
EXAMPLE_FILES+=	socks5.conf.gssapi socks5.conf.multipleservers
EXAMPLE_FILES+=	socks5.conf.server2server socks5.conf.singlehomed
EXAMPLE_DIR=	${PREFIX}/share/examples/socks5

post-install:
	${MV} ${PREFIX}/lib/libsocks5_sh.so ${PREFIX}/lib/libsocks5_sh.so.0.0
	${LN} -sf libsocks5_sh.so.0.0 ${PREFIX}/lib/libsocks5_sh.so.0
	${LN} -sf libsocks5_sh.so.0.0 ${PREFIX}/lib/libsocks5_sh.so
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLE_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
