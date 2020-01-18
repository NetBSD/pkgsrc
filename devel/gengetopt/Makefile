# $NetBSD: Makefile,v 1.2 2020/01/18 23:30:28 rillig Exp $

DISTNAME=	gengetopt-2.22.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gengetopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gengetopt/
COMMENT=	Command line parser generator
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
# complains about missing ../src/somelibrary.la
MAKE_JOBS_SAFE=	no
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
