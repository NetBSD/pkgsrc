# $NetBSD: Makefile,v 1.13 2020/03/20 11:57:24 nia Exp $

DISTNAME=	thrulay-0.9
CATEGORIES=	benchmarks net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thrulay/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thrulay.sourceforge.net/
COMMENT=	TCP and UDP network capacity tester
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/thrulay

.include "../../mk/bsd.pkg.mk"
