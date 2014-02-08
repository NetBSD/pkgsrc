# $NetBSD: Makefile,v 1.23 2014/02/08 15:54:58 jmmv Exp $
#

DISTNAME=	atf-0.20
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/atf/releases/download/${DISTNAME}/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://github.com/jmmv/atf/
COMMENT=	Automated testing framework
LICENSE=	2-clause-bsd

CONFLICTS+=		atf-libs<0.20

MAKE_JOBS_SAFE=		yes

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	ATF_SHELL=${SH:Q}

PKGCONFIG_OVERRIDE=	atf-c/atf-c.pc.in
PKGCONFIG_OVERRIDE+=	atf-c++/atf-c++.pc.in
PKGCONFIG_OVERRIDE+=	atf-sh/atf-sh.pc.in

.include "../../mk/bsd.pkg.mk"
