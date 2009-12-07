# $NetBSD: Makefile,v 1.2 2009/12/07 16:39:12 wiz Exp $
#

DISTNAME=	frama-c-Beryllium-20090901
PKGNAME=	${DISTNAME:S/-Beryllium//}
CATEGORIES=	devel
MASTER_SITES=	http://frama-c.cea.fr/download/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://frama-c.cea.fr/
COMMENT=	Extensible platform dedicated to source-code analysis of C software
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "options.mk"

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
