# $NetBSD: Makefile,v 1.12 2001/09/27 23:18:32 jlam Exp $
#

DISTNAME=	export.socks.cstc.4.2.2
PKGNAME=	socks4-2.2
WRKSRC=		${WRKDIR}/socks.cstc.4.2
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.nec.com/pub/socks/socks4/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.socks.nec.com/socksv4.html
COMMENT=	Old library, server and client for using proxy firewall software

CONFLICTS=	socks5-[0-9]*

RESTRICTED=		"no commercial use"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK_ONLY=	# defined
MAKE_ENV+=		OPTIMIZE="${CFLAGS}"

post-patch:
	@cd ${WRKSRC};							\
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		include/socks.h > ${WRKSRC}/include/socks.h.new;	\
	${MV} include/socks.h.new include/socks.h
	@${ECHO} "sockd 0.0.0.0 0.0.0.0" >> ${WRKSRC}/socks.conf

.include "../../mk/bsd.pkg.mk"
