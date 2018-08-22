# $NetBSD: Makefile,v 1.73 2018/08/22 09:46:33 wiz Exp $

PKGREVISION= 1
.include "../../sysutils/coreutils/Makefile.common"

CONFIGURE_ARGS+=	--without-gmp

CONFLICTS=	fileutils-[0-9]* gnuls-[0-9]* linuxls-[0-9]* sh-utils-[0-9]* textutils-[0-9]*

# devel/id-utils installs a 'gid' program, so conflict with it
# databases/geneweb a 'gwc' program, so conflict with it
# graphics/graphviz installs a 'gpr' program, so conflict with it
CONFLICTS+=		id-utils-[0-9]* gnome-utils<1.4.1.2nb2
CONFLICTS+=		geneweb-[0-9]*
CONFLICTS+=		graphviz<1.12

INFO_FILES=		yes

# Exclude programs from PLIST which aren't built on a platform.
PLIST_VARS+=		hostid stdbuf
.if ${OPSYS} != "Interix"
PLIST.hostid=		yes
.endif

# This should really only be defined if building stdbuf, however we cannot
# set this variable after including compiler.mk, so we take the hit of
# setting it unconditionally for now.
USE_GCC_RUNTIME=	yes

.include "../../mk/compiler.mk"

.if (${OBJECT_FMT} == "ELF" || ${OBJECT_FMT} == "Mach-O") && \
    (!empty(PKGSRC_COMPILER:Mgcc) || !empty(PKGSRC_COMPILER:Mclang))
PLIST.stdbuf=		yes
.endif

# Ensure libstdbuf.so has a valid library name otherwise REQUIRES will
# record the relative path of the object output file.
SUBST_CLASSES.Darwin+=	libname
SUBST_STAGE.libname=	pre-configure
SUBST_FILES.libname=	Makefile.in
SUBST_SED.libname=	-e '/^src_libstdbuf_so_LDFLAGS/s,$$, -install_name ${PREFIX}/libexec/coreutils/glibstdbuf.so,'

PROGS=	[ b2sum base32 base64 basename cat chcon chgrp chmod chown chroot cksum comm \
	cp csplit cut date dd df dir dircolors dirname du hostid echo env \
	expand expr factor false fmt fold groups head id install join kill \
	link ln logname ls md5sum mkdir mkfifo mknod mktemp mv nice nl \
	nohup nproc numfmt od paste pathchk pinky pr printenv printf ptx pwd \
	readlink realpath rm rmdir runcon seq sha1sum sha224sum sha256sum \
	sha384sum sha512sum shred shuf sleep sort split stat stdbuf stty sum \
	sync tac tail tee test timeout touch tr true truncate tsort tty uname \
	unexpand uniq unlink uptime users vdir wc who whoami yes

AUTO_MKDIRS=	yes

post-install:
.for f in ${PROGS}
	set -e; \
	if ${TEST} -f ${DESTDIR}${PREFIX}/bin/g${f:Q}; then \
	  ${LN} -sf ${PREFIX}/bin/g${f:Q} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f:Q}; \
	fi; \
	if ${TEST} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/g${f:Q}.1; then \
	  ${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f:Q}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f:Q}.1; \
	fi
.endfor

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
