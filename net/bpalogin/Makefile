# $NetBSD: Makefile,v 1.6 2003/07/17 22:51:01 grant Exp $
#

DISTNAME=	bpalogin-2.0.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bpalogin/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bpalogin.sourceforge.net/
COMMENT=	BigPond Advance login client

ALL_TARGET=	bpalogin

USE_PKGINSTALL=	yes
CONF_FILES+=	${PREFIX}/share/examples/bpalogin/bpalogin.conf \
		${PKG_SYSCONFDIR}/bpalogin.conf
RCD_SCRIPTS=	bpalogin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpalogin ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bpalogin
	${INSTALL_DATA} ${WRKSRC}/bpalogin.conf				\
		${PREFIX}/share/examples/bpalogin

.include "../../mk/bsd.pkg.mk"
