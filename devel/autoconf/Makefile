# $NetBSD: Makefile,v 1.27 2001/08/28 14:58:15 skrll Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Automatically configure source code on many Un*x platforms

DEPENDS=	m4-1.4:../../devel/m4

USE_PERL5=	yes
M4=		${PREFIX}/bin/gm4

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	AWK="${AWK}"
INFO_FILES=	autoconf.info standards.info

.include "../../mk/bsd.pkg.mk"
