# $NetBSD: Makefile,v 1.45 2004/12/01 21:24:30 xtraeme Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.6.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU:=gv/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gv/
COMMENT=	PostScript and PDF previewer

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/gv

USE_MAKEINFO=		yes
INFO_FILES=		gv.info

XAW_TYPE=		3d

SUBST_CLASSES+=		sh
SUBST_STAGE.sh=		post-patch
SUBST_FILES.sh=		configure
SUBST_SED.sh=		-e "s|==|=|g"
SUBST_MESSAGE.sh=	"Fixing configure script."

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
