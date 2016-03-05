# $NetBSD: Makefile,v 1.52 2016/03/05 09:08:46 ryoon Exp $

DISTNAME=	gdb-7.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends
LICENSE=	gnu-gpl-v3

BROKEN_GETTEXT_DETECTION=	yes
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake msgfmt makeinfo perl:build
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=		install install-info
TEST_TARGET=		check
INFO_FILES=		yes
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

# In gdb/configure, depcomp is parsed with sed.
SUBST_CLASSES+=			fix-depcomp
SUBST_STAGE.fix-depcomp+=	pre-configure
SUBST_MESSAGE.fix-depcomp+=	Read depcomp directly
SUBST_FILES.fix-depcomp+=	gdb/configure
SUBST_SED.fix-depcomp+=		-e 's,< ./depcomp,${PREFIX}/share/libtool/config/depcomp,'

AUTO_MKDIRS=		yes

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.elif ${OPSYS} == "NetBSD"
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+= -with-curses
CONFIGURE_ENV+= gdb_cv_var_elf=yes
MAKE_ENV+= gdb_cv_var_elf=yes
CONFIGURE_ENV+= gdb_cv_struct_lwp=yes
MAKE_ENV+= gdb_cv_struct_lwp=yes

.elif ${OPSYS} == "DragonFly"
TARGET_STR=		${MACHINE_ARCH}--dragonfly
BUILD_DEFS+=		${TARGET_STR}
## Remove "-pc" string, without this, getting following message:
##	   *** Gdb does not support native target i386-pc-dragonfly"
CONFIGURE_ARGS+=		--target=${TARGET_STR}
TEST_ENV=		DEJAGNU=${WRKDIR}/../files/dragonfly-default.exp
.endif

post-install:
.if ${OPSYS} == "DragonFly"
# Following are installed by binutils
#. for f in ansidecl.h bfdlink.h dis-asm.h symcat.h
#	(cd ${WRKSRC}/include; ${INSTALL_DATA} ${f}  ${DESTDIR}${PREFIX}/include)
#. endfor
	(cd ${DESTDIR}${PREFIX}/bin;               ${LN} ${TARGET_STR}-gdb gdb)
	(cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; ${LN} ${TARGET_STR}-gdb.1 gdb.1)
.endif
#
# PATH of libiberty.a differs between clang and gcc: (and conflicts to other toolchain)
# Rename to avoid conflict to native and other toolchain
# and clang differs its path so, (the same as avr-binutils).

	(cd ${DESTDIR}${PREFIX};				\
	for d in ${MACHINE_ARCH}/libiberty.a libiberty.a;	\
	  do if [ -f lib/$$d ]; then				\
		${MV}	lib/$$d	 lib/gdb/libiberty.a;		\
		break;						\
	     fi;						\
	  done;	)

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
