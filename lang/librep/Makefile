# $NetBSD: Makefile,v 1.9 2001/05/22 06:59:25 jlam Exp $
#

DISTNAME=		librep-${REP_VERS}
REP_VERS=		0.13.2
CATEGORIES=		lang devel
MASTER_SITES=		ftp://librep.sourceforge.net/pub/librep/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

DEPENDS+=		gmp>=3.0:../../devel/gmp
DEPENDS+=		gdbm>=1.8.0:../../databases/gdbm

# Uses GNU readline's rl_basic_quote_characters.
DEPENDS+=		readline>=4.0:../../devel/readline

USE_GMAKE=		# defined
USE_LIBINTL=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp-prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-gdbm-prefix=${LOCALBASE}

PLIST_SUBST+=		REP_VERS=${REP_VERS}

.include "../../mk/bsd.pkg.mk"
