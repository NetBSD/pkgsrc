# $NetBSD: Makefile,v 1.3 2023/06/06 12:42:05 riastradh Exp $

DISTNAME=	nanomsgxx-0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=achille-roussel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/achille-roussel/nanomsgxx/
COMMENT=	Nanomsg binding for C++11
LICENSE=	mit

USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	waf>=1.8.4:../../devel/waf

WAF_HAS_MANDIR=		no
WAF_REPLACE_EXECUTABLE=	yes

PKGCONFIG_OVERRIDE+=	libnnxx.pc.in

.include "../../net/nanomsg/buildlink3.mk"
.include "../../devel/waf/waf.mk"
.include "../../mk/bsd.pkg.mk"
