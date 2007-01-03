# $NetBSD: Makefile,v 1.2 2007/01/03 15:52:42 tv Exp $

DISTNAME=	mping-2.01
CATEGORIES=	net
MASTER_SITES=	http://mping.uninett.no/

MAINTAINER=	miwi@FreeBSD.org
HOMEPAGE=	http://mping.uninett.no/
COMMENT=	Mping network statistics collector

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mping ${PREFIX}/sbin/mping
	${INSTALL_MAN} ${WRKSRC}/man/mping.8 ${PREFIX}/${PKGMANDIR}/man8

PKG_OPTIONS_VAR=		PKG_OPTIONS.mping
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
