# $NetBSD: Makefile,v 1.3 2019/09/20 11:22:55 nia Exp $

DISTNAME=	schismtracker-20190805.source
PKGNAME=	${DISTNAME:S/.source//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=schismtracker/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	http://schismtracker.org/
COMMENT=	Clone of the good old Impulse Tracker
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/schismtracker
USE_TOOLS+=	autoreconf automake autoconf
MAKE_JOBS_SAFE=	no
GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/SDL/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
