# $NetBSD: Makefile,v 1.5 2003/06/02 01:18:02 jschauma Exp $
#

DISTNAME=	bpalogin-2.0.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bpalogin/}

MAINTAINER=	tech-pkg@netbsd.org
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
