# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 18:34:08 cjep Exp $
#

DISTNAME=	qadsl-final-1.2
PKGNAME=	qadsl-1.2
CATEGORIES=	net
MASTER_SITES=	http://qba.linuxsweden.nu/code/

MAINTAINER=	packages@netbsd.org
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
