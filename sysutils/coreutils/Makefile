# $NetBSD: Makefile,v 1.52 2011/10/03 16:17:08 jmmv Exp $

.include "../../sysutils/coreutils/Makefile.common"

CONFLICTS=	fileutils-[0-9]* gnuls-[0-9]* linuxls-[0-9]* sh-utils-[0-9]* textutils-[0-9]*

# if GNU_PROGRAM_PREFIX == 'g'
# devel/id-utils installs a 'gid' program, so conflict with it
# databases/geneweb a 'gwc' program, so conflict with it
# graphics/graphviz installs a 'gpr' program, so conflict with it
.if ${GNU_PROGRAM_PREFIX} == "g"
CONFLICTS+=		id-utils-[0-9]* gnome-utils<1.4.1.2nb2
CONFLICTS+=		geneweb-[0-9]*
CONFLICTS+=		graphviz<1.12
.endif
# print/teTeX-bin installed a 'readlink' program, so
# conflict with it if GNU_PROGRAM_PREFIX == '' (no problem in teTeX3-bin)
.if empty(GNU_PROGRAM_PREFIX)
CONFLICTS+=		teTeX-bin<3
CONFLICTS+=		mktemp-[0-9]*
.endif

INFO_FILES=		yes

# Exclude programs from PLIST which aren't built on a platform.
PLIST_VARS+=		hostid stdbuf
.if ${OPSYS} != "Interix"
PLIST.hostid=		yes
.endif
.if ${OBJECT_FMT} == "ELF" && !empty(PKGSRC_COMPILER:Mgcc)
PLIST.stdbuf=		yes
.endif

#CONFIGURE_ARGS+=	--enable-install-program=su
#.if ${OPSYS} == "NetBSD" ||  ${OPSYS} == "FreeBSD" || \
#  ${OPSYS} == "OpenBSD"
#MAKE_FLAGS+=		setuid_root_mode=a=rx
#MESSAGE_SRC=		${.CURDIR}/MESSAGE.gsu
#MESSAGE_SUBST+=	OPSYS=${OPSYS:Q}
#.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
