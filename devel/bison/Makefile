# $NetBSD: Makefile,v 1.12 2000/01/10 19:11:07 hubertf Exp $

DISTNAME=	bison-1.28
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=bison/}

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bison/bison.html

DEPENDS+=	gettext-0.10.*:../../devel/gettext

GNU_CONFIGURE=	yes

INFO_FILES=	bison.info

CPPFLAGS+=	-Dunix				# for $TMPDIR parsing
CPPFLAGS+=	-I${LOCALBASE}/include		# for libintl.h
INTLLIBS=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" INTLLIBS="${INTLLIBS}"

.include "../../mk/bsd.pkg.mk"
