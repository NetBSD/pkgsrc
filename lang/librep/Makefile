# $NetBSD: Makefile,v 1.16 2001/10/21 11:07:11 wiz Exp $
#

DISTNAME=		librep-${REP_VERS}
REP_VERS=		0.14
CATEGORIES=		lang devel
MASTER_SITES=		ftp://librep.sourceforge.net/pub/librep/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

BUILDLINK_DEPENDS.gdbm=	gdbm>=1.8.0
USE_GNU_READLINE=	# uses rl_basic_quote_characters

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp

PLIST_SUBST+=		REP_VERS=${REP_VERS}

.include "../../databases/gdbm/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/gmp/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
