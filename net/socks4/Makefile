# $NetBSD: Makefile,v 1.14 2003/05/01 22:03:49 jmmv Exp $
#

DISTNAME=	export.socks.cstc.4.2.2
PKGNAME=	socks4-2.2
PKGREVISION=	1
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

USE_BUILDLINK2=		# defined
USE_PKGINSTALL=		yes
MAKE_ENV+=		OPTIMIZE="${CFLAGS}"

EGDIR=		${PREFIX}/share/examples/socks4
CONF_FILES=	${EGDIR}/socks.conf ${PKG_SYSCONFDIR}/socks.conf

post-patch:
	@cd ${WRKSRC};							\
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"		\
		include/socks.h > ${WRKSRC}/include/socks.h.new;	\
	${MV} include/socks.h.new include/socks.h
	@${ECHO} "sockd 0.0.0.0 0.0.0.0" >> ${WRKSRC}/socks.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
