# $NetBSD: Makefile,v 1.9 1998/04/15 10:38:40 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/28 06:49:06 obrien Exp
#

DISTNAME=	socks5-v1_0r2_tar
PKGNAME=	socks5-1.0.2
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.astec.co.jp/pub/security/socks/  \
		ftp://ftp.ualg.pt/Linux/net/proxies/socks5/
EXTRACT_SUFX=	.gz

MAINTAINER=	ambrisko@ambrisko.roble.com

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
MAN1=		runsocks.1 socks5.1 stopsocks.1 socks5_clients.1
MAN5=		libsocks5.conf.5 socks5.conf.5 socks5.passwd.5

post-install:
	ln -fs ${PREFIX}/lib/libsocks5_sh.so ${PREFIX}/lib/libsocks5_sh.so.0.0
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
