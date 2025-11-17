# $NetBSD: Makefile,v 1.14 2025/11/17 11:00:24 wiz Exp $

DISTNAME=	thrulay-0.9
CATEGORIES=	benchmarks net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thrulay/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thrulay.sourceforge.net/
COMMENT=	TCP and UDP network capacity tester
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/thrulay

.include "../../mk/bsd.pkg.mk"
