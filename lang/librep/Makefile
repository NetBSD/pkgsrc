# $NetBSD: Makefile,v 1.58 2012/09/15 10:05:19 obache Exp $
#

DISTNAME=		librep-0.91.0
PKGREVISION=		4
CATEGORIES=		lang devel
MASTER_SITES=		http://download.tuxfamily.org/sawfish/librep/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://librep.sourceforge.net/
COMMENT=		Emacs Lisp-like runtime library, interpreter, compiler and VM

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		gmake makeinfo
USE_GNU_READLINE=	yes # uses rl_basic_quote_characters
USE_LIBTOOL=		yes
# we have a symlink to libtool
DEPENDS+=		libtool-base-[0-9]*:../../devel/libtool-base
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	librep.pc.in

REP_LIBTOOL=		${PREFIX}/lib/rep/${MACHINE_GNU_PLATFORM}/libtool

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

post-install:
	${RM} -f ${DESTDIR}${REP_LIBTOOL}
	${LN} -s ${PKG_LIBTOOL} ${DESTDIR}${REP_LIBTOOL}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
