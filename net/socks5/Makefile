# $NetBSD: Makefile,v 1.14 1999/02/20 22:26:22 hubertf Exp $
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

CONFLICTS=	socks4-*

NO_CDROM=	"NEC has a funky license for this software"
RESTRICTED=	"no commercial use"

# here are some extra configure args you may wish to use
# see the readme file before screwing with them
#
#EXTRA_CONFIGURE_ARGS+= \
#		--with-default-server=socks.mydomain.com \
#		--with-syslog-facility=LOG_AUTH \
#		--with-passwd

WRKSRC=		${WRKDIR}/socks5-v1.0r2
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=  LIBS=-lcrypt
CONFIGURE_ARGS=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
		--with-srvconffile=${PREFIX}/etc/socks5.conf \
		--with-srvpidfile=/var/run/socks5.pid \
		--with-srvidtfile=/var/run/socks5.ident \
		${EXTRA_CONFIGURE_ARGS}

post-install:
	${LN} -fs ${PREFIX}/lib/libsocks5_sh.so ${PREFIX}/lib/libsocks5_sh.so.0.0

.include "../../mk/bsd.pkg.mk"
