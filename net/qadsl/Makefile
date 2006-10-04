# $NetBSD: Makefile,v 1.9 2006/10/04 21:53:18 wiz Exp $
#
# qadsl is now GNU Alive (wip/alive)

DISTNAME=	qadsl-final-1.2
PKGNAME=	qadsl-1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Login software for Swedish Telia ADSL/Comhem cable Internet users

LIBS.SunOS+=	-lnsl -lsocket

MANCOMPRESSED=	yes

MAKE_ENV+=	LIBS=${LIBS:M*:Q}
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	man/man8 sbin share/examples

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qadsl ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/qadsl.conf \
		${PREFIX}/share/examples/qadsl.conf.sample
	${INSTALL_MAN} ${WRKSRC}/qadsl.8.gz ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
