# $NetBSD: Makefile,v 1.6 2000/10/27 17:47:01 jlam Exp $
#

DISTNAME=		librep-${REP_VERS}
REP_VERS=		0.13.2
CATEGORIES=		lang devel
MASTER_SITES=		ftp://librep.sourceforge.net/pub/librep/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://librep.sourceforge.net/

DEPENDS+=		gmp>=3.0:../../devel/gmp
DEPENDS+=		gdbm>=1.8.0:../../databases/gdbm
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=		readline>=4.0:../../devel/readline

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp-prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-gdbm-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LIBS="-lintl"

PLIST_SUBST+=		REP_VERS=${REP_VERS}

.include "../../mk/bsd.pkg.mk"
