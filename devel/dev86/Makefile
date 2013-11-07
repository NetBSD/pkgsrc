# $NetBSD: Makefile,v 1.7 2013/11/07 14:01:47 obache Exp $
#

DISTNAME=	Dev86src-0.16.19
PKGNAME=	${DISTNAME:tl:S/src-/-/}
CATEGORIES=	devel
MASTER_SITES=	http://www.debath.co.uk/dev86/

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
