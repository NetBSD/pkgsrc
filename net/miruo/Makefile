# $NetBSD: Makefile,v 1.3 2016/06/09 06:23:40 wiz Exp $

DISTNAME=	miruo-0.9.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=KLab/}
GITHUB_PROJECT=	miruo
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/KLab/miruo/
COMMENT=	Pretty-print TCP session monitor/analyzer
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Fixing getopt_long_only
SUBST_FILES.getopt+=	miruo.c
SUBST_SED.getopt+=	-e 's,getopt_long_only,getopt_long,'

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
