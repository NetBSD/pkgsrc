# $NetBSD: Makefile,v 1.39 2004/10/03 00:15:01 tv Exp $
#

DISTNAME=		librep-0.17
PKGREVISION=		1
CATEGORIES=		lang devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=librep/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_GNU_READLINE=	# uses rl_basic_quote_characters

USE_LIBTOOL=		yes
REP_LIBTOOL=		${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp
CONFIGURE_ARGS+=	--enable-static

CONFIG_STATUS_OVERRIDE=	# empty

USE_MAKEINFO=	YES
INFO_FILES=	librep.info

post-install:
	${RM} -f ${REP_LIBTOOL}
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} ${REP_LIBTOOL}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
