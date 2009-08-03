# $NetBSD: Makefile,v 1.3 2009/08/03 14:46:12 joerg Exp $
#

DISTNAME=	nant-0.86-beta1-src
PKGNAME=	nant-0.86beta1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nant.sourceforge.net/
COMMENT=	Free .NET build tool similar to Apache Ant

WRKSRC=		${WRKDIR}/nant-0.86-beta1
USE_LANGUAGES=	# csharp
USE_TOOLS+=	pkg-config gmake

MAKE_JOBS_SAFE=	no

PKG_DESTDIR_SUPPORT=	user-destdir

do-configure:
	cd ${WRKSRC} && ${GMAKE} setup

do-build:
	cd ${WRKSRC} && ${GMAKE} bootstrap

do-install:
	cd ${WRKSRC} && ${GMAKE} install prefix=${DESTDIR}${PREFIX} vprefix=${PREFIX}/share/NAnt

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
