# $NetBSD: Makefile,v 1.44 2003/06/19 21:49:50 seb Exp $

DISTNAME=		bison-1.875
PKGREVISION=		1
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

USE_NEW_TEXINFO=	YES
INFO_FILES=		bison.info

.include "../../mk/bsd.pkg.mk"
