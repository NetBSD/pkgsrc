# $NetBSD: Makefile,v 1.46 2007/05/07 12:42:19 tnn Exp $
#

DISTNAME=		librep-0.17
PKGREVISION=		3
CATEGORIES=		lang devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=librep/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

USE_TOOLS+=		gmake makeinfo
USE_GNU_READLINE=	# uses rl_basic_quote_characters

USE_LIBTOOL=		yes
REP_LIBTOOL=		${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp
CONFIGURE_ARGS+=	--enable-static

CONFIG_STATUS_OVERRIDE=	# empty

INFO_FILES=	# PLIST

post-install:
	${RM} -f ${REP_LIBTOOL}
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} ${REP_LIBTOOL}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
