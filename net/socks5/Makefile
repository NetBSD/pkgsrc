# $NetBSD: Makefile,v 1.19 2001/06/12 20:33:06 jlam Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/28 06:49:06 obrien Exp
#

DISTNAME=	socks5-v1_0r2_tar
PKGNAME=	socks5-1.0.2
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.astec.co.jp/pub/security/socks/  \
		ftp://ftp.ualg.pt/Linux/net/proxies/socks5/
EXTRACT_SUFX=	.gz

MAINTAINER=	ambrisko@ambrisko.roble.com
HOMEPAGE=	http://www.socks.nec.com/
COMMENT=	SOCKS v5 application layer gateway and clients

CONFLICTS=	socks4-*

RESTRICTED=	"no commercial use"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# here are some extra configure args you may wish to use
# see the readme file before screwing with them
#
#EXTRA_CONFIGURE_ARGS+= \
#		--with-default-server=socks.mydomain.com \
#		--with-syslog-facility=LOG_AUTH \
#		--with-passwd

WRKSRC=		${WRKDIR}/socks5-v1.0r2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
		--with-srvconffile=${PREFIX}/etc/socks5.conf \
		--with-srvpidfile=/var/run/socks5.pid \
		--with-srvidtfile=/var/run/socks5.ident \
		${EXTRA_CONFIGURE_ARGS}
LIBS=		-lcrypt

post-install:
	${MV} ${PREFIX}/lib/libsocks5_sh.so ${PREFIX}/lib/libsocks5_sh.so.0.0
	${LN} -sf libsocks5_sh.so.0.0 ${PREFIX}/lib/libsocks5_sh.so.0
	${LN} -sf libsocks5_sh.so.0.0 ${PREFIX}/lib/libsocks5_sh.so

.include "../../mk/bsd.pkg.mk"
