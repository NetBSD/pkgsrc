# $NetBSD: Makefile,v 1.7 2006/03/04 21:30:23 jlam Exp $
#

DISTNAME=	qadsl-final-1.2
PKGNAME=	qadsl-1.2
CATEGORIES=	net
MASTER_SITES=	http://qba.linuxsweden.nu/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qba.linuxsweden.nu/
COMMENT=	Login software for Swedish Telia ADSL/Comhem cable Internet users

LIBS.SunOS+=	-lnsl -lsocket

MANCOMPRESSED=	yes

MAKE_ENV+=	LIBS=${LIBS:M*:Q}
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qadsl ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/qadsl.conf \
		${PREFIX}/share/examples/qadsl.conf.sample
	${INSTALL_MAN} ${WRKSRC}/qadsl.8.gz ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
