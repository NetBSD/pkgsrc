# $NetBSD: Makefile,v 1.10 2022/12/05 14:34:37 fcambus Exp $

DISTNAME=	schismtracker-20221201
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=schismtracker/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	https://schismtracker.org/
COMMENT=	Clone of the good old Impulse Tracker
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoreconf automake autoconf
MAKE_JOBS_SAFE=	no
GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	tool

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/SDL2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
