# $NetBSD: Makefile,v 1.12.2.1 2019/01/12 09:40:22 bsiegert Exp $

DISTNAME=	megatools-1.10.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://megatools.megous.com/builds/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://megatools.megous.com/
COMMENT=	Command line client for Mega.co.nz
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
