# $NetBSD: Makefile,v 1.48 2005/02/12 23:01:59 snj Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp

DISTNAME=	gv-3.6.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU:=gv/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gv/
COMMENT=	PostScript and PDF previewer

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

USE_MAKEINFO=		yes
TEXINFO_REQD=		4.2
INFO_FILES=		gv.info

XAW_TYPE=		3d

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
