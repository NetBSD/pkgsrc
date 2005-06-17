# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:27 jlam Exp $
#

DISTNAME=	qadsl-final-1.2
PKGNAME=	qadsl-1.2
CATEGORIES=	net
MASTER_SITES=	http://qba.linuxsweden.nu/code/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://qba.linuxsweden.nu/
COMMENT=	Login software for Swedish Telia ADSL/Comhem cable Internet users

LIBS.SunOS=	-lnsl -lsocket

MANCOMPRESSED=	yes

MAKE_ENV+=	LIBS="${LIBS}"
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qadsl ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/qadsl.conf \
		${PREFIX}/share/examples/qadsl.conf.sample
	${INSTALL_MAN} ${WRKSRC}/qadsl.8.gz ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
