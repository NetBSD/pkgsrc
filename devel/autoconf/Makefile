# $NetBSD: Makefile,v 1.24 2000/04/04 23:18:24 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/autoconf/autoconf.html

DEPENDS=	m4-1.4:../../devel/m4

USE_PERL5=	yes
M4=		${PREFIX}/bin/gm4

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	AWK="${AWK}"
INFO_FILES=	autoconf.info standards.info

.include "../../mk/bsd.pkg.mk"
