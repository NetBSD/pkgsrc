# $NetBSD: Makefile,v 1.3 2003/07/17 22:51:44 grant Exp $
#

DISTNAME=	qadsl-final-1.2
PKGNAME=	qadsl-1.2
CATEGORIES=	net
MASTER_SITES=	http://qba.linuxsweden.nu/code/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://qba.linuxsweden.nu/
COMMENT=	Login software for Swedish Telia ADSL/Comhem cable Internet users

ALL_TARGET=	bsd
MANCOMPRESSED=	yes

MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qadsl ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/qadsl.conf \
		${PREFIX}/share/examples/qadsl.conf.sample
	${INSTALL_MAN} ${WRKSRC}/qadsl.8.gz ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
