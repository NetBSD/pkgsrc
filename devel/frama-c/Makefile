# $NetBSD: Makefile,v 1.40 2013/09/02 19:50:58 adam Exp $
#

DISTNAME=	frama-c-Oxygen-20120901
PKGNAME=	${DISTNAME:S/-Oxygen//}
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	http://frama-c.com/download/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://frama-c.com/
COMMENT=	Extensible platform dedicated to source-code analysis of C software
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "options.mk"

.include "../../x11/lablgtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
