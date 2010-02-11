# $NetBSD: Makefile,v 1.7 2010/02/11 21:43:39 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	0.2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

INSTALLATION_DIRS=	bin sbin

.include "../../mk/bsd.pkg.mk"
