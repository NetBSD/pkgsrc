# $NetBSD: Makefile,v 1.16 2001/01/12 23:33:38 jlam Exp $

DISTNAME=	bison-1.28
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=bison/}

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bison/bison.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

GNU_CONFIGURE=	yes

INFO_FILES=	bison.info

USE_LIBINTL=	YES
CPPFLAGS+=	-Dunix				# for $TMPDIR parsing
CONFIGURE_ARGS+=--without-included-gettext
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
