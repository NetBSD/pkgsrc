# $NetBSD: Makefile,v 1.22 1999/04/14 21:39:01 tron Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/autoconf/autoconf.html

DEPENDS=	m4-1.4:../../devel/m4

USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	M4=${PREFIX}/bin/gm4
INFO_FILES=	autoconf.info standards.info

.include "../../mk/bsd.pkg.mk"
