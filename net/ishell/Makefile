# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:25 joerg Exp $
#

DISTNAME=	ish-v${VERSION}
PKGNAME=	ishell-${VERSION}
WRKSRC=		${WRKDIR}/ISHELL-v${VERSION}/
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpshell/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpshell.sourceforge.net/
COMMENT=	Allow remote shell using ICMP

VERSION=	0.2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

INSTALLATION_DIRS=	bin sbin

.include "../../mk/bsd.pkg.mk"
