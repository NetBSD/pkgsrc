# $NetBSD: Makefile,v 1.2 2002/11/21 10:02:56 grant Exp $
#

DISTNAME=	bpalogin-2.0.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bpalogin/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bpalogin.sourceforge.net/
COMMENT=	BigPond Advance login client

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

ALL_TARGET=	bpalogin

CONF_FILES+=	${PREFIX}/share/examples/bpalogin/bpalogin.conf \
		${PKG_SYSCONFDIR}/bpalogin.conf
RCD_SCRIPTS=	bpalogin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpalogin ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bpalogin
	${INSTALL_DATA} ${WRKSRC}/bpalogin.conf				\
		${PREFIX}/share/examples/bpalogin

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
