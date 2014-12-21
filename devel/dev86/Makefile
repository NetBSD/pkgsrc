# $NetBSD: Makefile,v 1.8 2014/12/21 00:43:38 ryoon Exp $
#

DISTNAME=	dev86-0.16.21
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/lkundrak/dev86/archive/v0.16.21.tar.gz

MAINTAINER=	pierrick@bs-network.net
HOMEPAGE=	http://www.debath.co.uk/
COMMENT=	Linux 8086 development environment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

CONFLICTS=	bcc-[0-9]*
CONFLICTS+=	bin86-[0-9]*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

DESTDIR_VARNAME=	DIST

.include "../../mk/bsd.pkg.mk"
