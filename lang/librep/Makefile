# $NetBSD: Makefile,v 1.3 2000/07/01 03:39:44 danw Exp $
#

DISTNAME=		librep-0.12.2
CATEGORIES=		lang devel
MASTER_SITES=		ftp://librep.sourceforge.net/pub/librep/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://librep.sourceforge.net/

DEPENDS+=		gmp>=3.0:../../devel/gmp
DEPENDS+=		gdbm>=1.8.0:../../databases/gdbm
DEPENDS+=		readline>=4.0:../../devel/readline

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-readline --with-gmp-prefix=${LOCALBASE} \
			--with-gdbm-prefix=${LOCALBASE}
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/etc/ltconfig

.include "../../mk/bsd.pkg.mk"
