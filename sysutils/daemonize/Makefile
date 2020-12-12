# $NetBSD: Makefile,v 1.1 2020/12/12 13:22:24 nia Exp $

DISTNAME=	daemonize-1.7.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bmc/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.clapper.org/daemonize/
COMMENT=	Tool to run a command as a daemon
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

MAKE_FLAGS+=	INSTALL_MAN=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
