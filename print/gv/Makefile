# $NetBSD: Makefile,v 1.61 2006/10/23 12:29:56 tron Exp $

DISTNAME=	gv-3.6.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU:=gv/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gv/
COMMENT=	PostScript and PDF previewer

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gs:run makeinfo

TEXINFO_REQD=		4.2
INFO_FILES=		yes

# this pkg does not work with std xaw, but xpm and xaw3d work
XAW_TYPE?=		3d
.include "../../mk/bsd.prefs.mk"
.if ${XAW_TYPE} == "standard"
XAW_TYPE=		3d
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
