# $NetBSD: Makefile,v 1.1 2022/04/14 17:29:10 nikita Exp $

DISTNAME=	ATS2-Postiats-0.4.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ats2-lang/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ats-lang.org/
COMMENT=	Functional programming language with dependent types
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/ATS2-Postiats-int-${PKGVERSION_NOREV}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
# build is not job safe
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
