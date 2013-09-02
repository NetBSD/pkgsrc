# $NetBSD: Makefile,v 1.3 2013/09/02 19:51:26 adam Exp $

DISTNAME=	ruby-libnotify-0.5.1
PKGNAME=	${DISTNAME:S/ruby/${RUBY_PKGPREFIX}/}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	-https://github.com/vargolo/ruby-libnotify/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/vargolo/ruby-libnotify
COMMENT=	Ruby binding for libnotify
LICENSE=	gnu-lgpl-v2.1

USE_RUBY_SETUP=	yes

.include "../../x11/ruby-gnome2-gtk/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
