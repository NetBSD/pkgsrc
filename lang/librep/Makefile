# $NetBSD: Makefile,v 1.11 2001/06/10 00:08:45 jlam Exp $
#

DISTNAME=		librep-${REP_VERS}
REP_VERS=		0.13.2
CATEGORIES=		lang devel
MASTER_SITES=		ftp://librep.sourceforge.net/pub/librep/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

GDBM_REQD=		1.8.0
USE_GNU_READLINE=	# uses rl_basic_quote_characters

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../databases/gdbm/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/gmp/buildlink.mk"
.include "../../devel/readline/buildlink.mk"

CPPFLAGS+=		-I${BUILDLINK_INCDIR}
LDFLAGS+=		-L${BUILDLINK_LIBDIR}

PLIST_SUBST+=		REP_VERS=${REP_VERS}

.include "../../mk/bsd.pkg.mk"
