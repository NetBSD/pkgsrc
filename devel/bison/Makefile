# $NetBSD: Makefile,v 1.39 2002/12/15 19:41:26 cjep Exp $

DISTNAME=		bison-1.75
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cjep@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

DEPENDS+=		m4>=1.4:../../devel/m4
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

M4=			${LOCALBASE}/bin/gm4

INFO_FILES=		bison.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
