# $NetBSD: Makefile,v 1.17 2001/10/22 02:23:53 mycroft Exp $
#

DISTNAME=		librep-${REP_VERS}
REP_VERS=		0.15
CATEGORIES=		lang devel
MASTER_SITES=		http://prdownloads.sourceforge.net/librep/

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
CONFIGURE_ARGS+=	--enable-static

PLIST_SUBST+=		REP_VERS=${REP_VERS}

.include "../../databases/gdbm/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/gmp/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
