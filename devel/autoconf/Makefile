# $NetBSD: Makefile,v 1.14 1998/04/17 09:37:22 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	M4=${PREFIX}/bin/gm4
INFO_FILES=	autoconf standards

.include "../../mk/bsd.pkg.mk"
