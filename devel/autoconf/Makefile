# $NetBSD: Makefile,v 1.13 1998/04/15 10:38:19 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	M4=${PREFIX}/bin/gm4

post-install:
	@install-info ${PREFIX}/info/autoconf.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/standards.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
