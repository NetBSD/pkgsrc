# $NetBSD: Makefile,v 1.10 2013/01/26 21:37:23 adam Exp $
#

DISTNAME=	nant-0.86-beta1-src
PKGNAME=	nant-0.86beta1
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nant.sourceforge.net/
COMMENT=	Free .NET build tool similar to Apache Ant

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/nant-0.86-beta1
USE_LANGUAGES=	# csharp
USE_TOOLS+=	pkg-config gmake

BUILD_TARGET=		bootstrap

INSTALL_MAKE_FLAGS+=		prefix=${DESTDIR}${PREFIX} \
				vprefix=${PREFIX}/share/NAnt

do-configure:
	cd ${WRKSRC} &&	${SETENV} ${MAKE_ENV} ${GMAKE} setup

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
