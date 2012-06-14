# $NetBSD: Makefile,v 1.23 2012/06/14 07:43:53 sbd Exp $
#

DISTNAME=	frama-c-Nitrogen-20111001
PKGNAME=	${DISTNAME:S/-Nitrogen//}
PKGREVISION=	7
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
