# $NetBSD: Makefile,v 1.23 2002/02/18 15:14:10 seb Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/29 09:20:00 obrien Exp
#

DISTNAME=	indent-2.2.6
PKGNAME=	g${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--program-prefix=g

INFO_FILES=	indent.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
