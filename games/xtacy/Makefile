# $NetBSD: Makefile,v 1.2 2022/12/15 12:14:34 jperkin Exp $

DISTNAME=	xtacy114
PKGNAME=	xtacy-1.14
CATEGORIES=	games
MASTER_SITES=	https://web.archive.org/web/20000422141333/http://www.ultranet.com/~jjohnson/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20000422141333/http://www.gweep.net/~jer/xtacy.html
COMMENT=	Graphics hack for X11
LICENSE=	gnu-gpl-v2

# XXX: HACK: the tar.gz is not actually a gzip file
EXTRACT_ENV+=	GZCAT=cat

WRKSRC=		${WRKDIR}/Xtacy

USE_IMAKE=	yes

LDFLAGS.NetBSD+=	-lcrypt

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
