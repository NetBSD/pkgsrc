# $NetBSD: Makefile,v 1.22 2005/10/06 21:18:24 bad Exp $
#

DISTNAME=	export.socks.cstc.4.2.2
PKGNAME=	socks4-2.2
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.nec.com/pub/socks/socks4/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.socks.nec.com/socksv4.html
COMMENT=	Old library, server and client for using proxy firewall software

CONFLICTS=	socks5-[0-9]* dante*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/socks.cstc.4.2
USE_PKGINSTALL=		yes
MAKE_ENV+=		OPTIMIZE="${CFLAGS}"

EGDIR=		${PREFIX}/share/examples/socks4
CONF_FILES=	${EGDIR}/socks.conf ${PKG_SYSCONFDIR}/socks.conf

INSTALLATION_DIRS=	bin lib libexec man/man1 man/man5 man/man8

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
