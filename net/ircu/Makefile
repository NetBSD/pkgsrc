# $NetBSD: Makefile,v 1.2 1998/11/24 20:54:03 tv Exp $
#

DISTNAME=	ircu2.10.04
PKGNAME=	ircu-2.10.04
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.undernet.org/pub/irc/servers/current/ \
		ftp://ftp.asu.net/pub/irc/servers/undernet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://coder-com.undernet.org/

GNU_CONFIGURE=	yes
IS_INTERACTIVE=	yes

post-configure:
	@${CP} ${FILESDIR}/config ${WRKSRC}/config/.config
	@cd ${WRKSRC} && \
		${MAKE} PREFIX="${PREFIX}" CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" config

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/ircd ${PREFIX}/share/doc/ircd
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/ircd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/chkconf ${PREFIX}/sbin/ircd-chkconf
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf \
		${PREFIX}/etc/ircd/ircd.conf.example
	cd ${WRKSRC}/doc && ${INSTALL_DATA} readme.crules readme.who \
		${PREFIX}/share/doc/ircd/

.include "../../mk/bsd.pkg.mk"
