# $NetBSD: Makefile,v 1.13 1998/09/04 21:56:41 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/29 09:20:00 obrien Exp
#

DISTNAME=	indent-1.9.1
PKGNAME=	gindent-1.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	kchowksey@hss.hns.com
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html

GNU_CONFIGURE=	yes

INFO_FILES=	gindent.info

MAKEFILE=	makefile

# agc - force makeinfo to create a new info file with the Dir info.
pre-install:
	@rm -f indent.info

.include "../../mk/bsd.pkg.mk"
