# $NetBSD: Makefile,v 1.31 2017/09/04 18:00:59 wiz Exp $
#

DISTNAME=	export.socks.cstc.4.2.2
PKGNAME=	socks4-2.2
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.nec.com/pub/socks/socks4/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.socks.nec.com/socksv4.html
COMMENT=	Old library, server and client for using proxy firewall software

CONFLICTS=	socks5-[0-9]* dante*

WRKSRC=			${WRKDIR}/socks.cstc.4.2
MAKE_ENV+=		OPTIMIZE=${CFLAGS:M*:Q}

EGDIR=		${PREFIX}/share/examples/socks4
CONF_FILES=	${EGDIR}/socks.conf ${PKG_SYSCONFDIR}/socks.conf

INSTALLATION_DIRS=	bin lib libexec ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8 ${EGDIR}

post-patch:
	@cd ${WRKSRC};							\
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"		\
		include/socks.h > ${WRKSRC}/include/socks.h.new;	\
	${MV} include/socks.h.new include/socks.h
	@${ECHO} "sockd 0.0.0.0 0.0.0.0" >> ${WRKSRC}/socks.conf

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../mk/bsd.pkg.mk"
