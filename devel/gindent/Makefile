# $NetBSD: Makefile,v 1.26 2002/09/01 13:50:07 tron Exp $
#

DISTNAME=	indent-2.2.8a
PKGNAME=	g${DISTNAME:S/a/.1/}
CATEGORIES=	devel
MASTER_SITES=	http://home.hccnet.nl/d.ingamells/
#MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--program-prefix=g

INFO_FILES=	indent.info

MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
