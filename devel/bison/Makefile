# $NetBSD: Makefile,v 1.19 2001/02/28 23:31:06 jlam Exp $

DISTNAME=		bison-1.28
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}

MAINTAINER=		thorpej@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

BUILD_DEPENDS+=		msgfmt:../../devel/gettext

USE_LIBINTL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

CPPFLAGS+=		-Dunix		# for $TMPDIR parsing

INFO_FILES=		bison.info

.include "../../mk/bsd.pkg.mk"
