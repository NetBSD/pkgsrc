# $NetBSD: Makefile,v 1.9 2001/02/17 18:19:39 wiz Exp $
#

DISTNAME=	export.socks.cstc.4.2.2
PKGNAME=	socks4-2.2
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.nec.com/pub/socks/socks4/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.socks.nec.com/socksv4.html
COMMENT=	Old library, server and client for using proxy firewall software

CONFLICTS=	socks5-*

RESTRICTED=	"no commercial use"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/socks.cstc.4.2

NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CC=gcc CPPFLAGS=
.endif

post-patch:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/include/socks.h \
		> ${WRKSRC}/include/socks.h.new && \
		${MV} ${WRKSRC}/include/socks.h.new ${WRKSRC}/include/socks.h
	@${ECHO} "sockd 0.0.0.0 0.0.0.0" >> ${WRKSRC}/socks.conf

.include "../../mk/bsd.pkg.mk"
