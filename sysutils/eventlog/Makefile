# $NetBSD: Makefile,v 1.2 2012/10/23 19:51:00 asau Exp $

VERS=		0.2.12
DISTNAME=	eventlog_${VERS}
PKGNAME=	eventlog-${VERS}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/open-source-edition/3.2.4/source/
WRKSRC=		${WRKDIR}/${PKGNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.balabit.com/network-security/syslog-ng/
COMMENT=	Support library for syslog-ng
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.pkg.mk"
