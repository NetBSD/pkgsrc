# $NetBSD: Makefile,v 1.2 2019/07/28 18:56:11 nia Exp $

# The upstream distfile (http://schismtracker.org/hg/archive/default.tar.bz2)
# is a repository snapshot and as such a moving target.
# Thus it's repackaged (adding a timestamp) and mirrored.
DISTNAME=	schismtracker-20150911005204
CATEGORIES=	audio
MASTER_SITES=	http://penenen.de/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	http://schismtracker.org/
COMMENT=	Clone of the good old Impulse Tracker
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	aclocal autoheader autoconf automake

MAKE_JOBS_SAFE=	no
GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	yes

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/SDL/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
