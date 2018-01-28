# $NetBSD: Makefile,v 1.64 2018/01/28 20:10:53 wiz Exp $
#

DISTNAME=		librep-0.92.3
PKGREVISION=		1
CATEGORIES=		lang devel
MASTER_SITES=		http://download.tuxfamily.org/librep/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sawfish.wikia.com/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

USE_TOOLS+=		gmake makeinfo gzip
USE_LIBTOOL=		yes
# we have a symlink to libtool
DEPENDS+=		libtool-base-[0-9]*:../../devel/libtool-base
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	librep.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-gmp
CONFIGURE_ARGS+=	--enable-static

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--with-stack-direction=-1
.endif

REPLACE_INTERPRETER+=	rep
REPLACE.rep.old=	.*/bin/rep
REPLACE.rep.new=	${PREFIX}/bin/rep
REPLACE_FILES.rep=	src/rep-xgettext.jl

SUBST_CLASSES+=		fixwrap
SUBST_STAGE.fixwrap=	post-build
SUBST_FILES.fixwrap=	libtool
SUBST_SED.fixwrap=	-e "s,${WRAPPER_BINDIR}/libtool,${PKG_LIBTOOL},g"

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
# uses rl_basic_quote_characters
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
