# $NetBSD: Makefile,v 1.17 2001/01/12 23:34:50 jlam Exp $

DISTNAME=		bison-1.28
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}

MAINTAINER=		thorpej@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html

BUILD_DEPENDS+=		msgfmt:../../devel/gettext

USE_LIBINTL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-Dunix		# for $TMPDIR parsing

INFO_FILES=		bison.info

.include "../../mk/bsd.pkg.mk"
