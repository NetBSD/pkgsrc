# $NetBSD: Makefile,v 1.26.2.2 2012/10/09 19:11:01 tron Exp $
#

DISTNAME=	frama-c-Oxygen-20120901
PKGNAME=	${DISTNAME:S/-Oxygen//}
CATEGORIES=	devel
MASTER_SITES=	http://frama-c.com/download/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://frama-c.com/
COMMENT=	Extensible platform dedicated to source-code analysis of C software
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "options.mk"

.include "../../x11/lablgtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
